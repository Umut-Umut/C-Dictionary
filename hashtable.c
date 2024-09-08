﻿#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "hashtable.h"

// Allocate a memory location to use as a sentinel value for items marked as deleted (similar to NULL pointer)
// Türkçesi, kendi adresini tutan bir işaretçiymiş. Yani doğal olarak yalnızca kendisine ait bi adres.
static void* DELETED = &DELETED;

static int findNextPrime(int x)
{
	// Just return 7, we don't want to deal with small sizes
	if (x < 7)
	{
		return 7;
	}

	if (0 == x % 2)
	{
		// If its even number, increase it, evens can't be primes
		x++;
	}
	else
	{
		// We want to find next prime, if number is odd, increase by 2
		x += 2;
	}

	// Lowest x is 9, sqrt(9) = 3, 3 <= 3 will run once at least
	for (int i = 3; i <= floor(sqrt(x)); i += 2)
	{
		if (0 == (x % i))
		{
			i = 1;
			x += 2;
		}
	}

	return x;
}
// Polynomial rolling hash function
static int hash(const void* key, int prime, int size)
{
	ItemData *data_key = (ItemData *)key;
	char *str_key = (char *)key;

	// const int n = strlen(key);
	int n = data_key->item_size;
	int hash = 0;
	for (int i = 0; i < n; i++)
	{
		if (str_key[i] < 0) continue;

		hash += ((unsigned)pow(prime, i) % size) * (str_key[i] % size);
		hash %= size;
	}

	return hash;
}
// Open addressing, we will use double hashing
static int doubleHash(const void* key, int size, int attempt)
{
	// We're hashing ASCII strings, which has an alphabet size of 128 
	// We should choose a prime larger than that 151, 163 should do
	const int firstHash  = hash(key, 151, size);
	const int secondHash = hash(key, 163, size-1) + 1;

	int finalHash = firstHash + attempt * secondHash;
	finalHash %= size;

	return finalHash;
}
static Item* allocItem(const void* key, const void* value)
{
	Item* item = malloc(sizeof(Item));
	if (NULL == item)
	{
		return NULL;
	}

	// strdup ile key ve value parametrelerini dinamik bir adrese kopyalıyor.
	// item->key   = _strdup(key);
	// item->value = _strdup(value);

	ItemData *data_key = (ItemData *)key, *data_value = (ItemData *)value;

	// item->key = (void *)calloc(data_key->item_size, sizeof(void));
	// item->value = (void *)calloc(data_value->item_size, sizeof(void));

	item->key = (void *)malloc(data_key->item_size);
	item->value = (void *)malloc(data_value->item_size);

	item->type_key = data_key->type;
	item->type_value = data_value->type;

	memcpy(item->key, key, data_key->item_size);
	memcpy(item->value, value, data_value->item_size);

	return item;
}
static void freeItem(Item* item)
{
	if (item == NULL || item == DELETED)
	{
		return;
	}
	free(item->key);
	free(item->value);
	free(item);
}
static Table* allocTable(int size)
{
	Table* table = malloc(sizeof(Table));
	if (NULL == table)
	{
		return NULL;
	}

	// next prime is 47 for 50
	table->size = findNextPrime(size);
	table->count = 0;
	table->items = calloc(table->size, sizeof(Item*));

	return table;
}
static Item** search(Table* table, const void* key, bool findInsertLocation)
{
	int attempt = 0;
	// Search until we find the key matching or we find an empty slot
	for (;;)
	{
		int index = doubleHash(key, table->size, attempt);
		attempt++;

		// Table.items dizisindeki indexte bulunan Item * i tutuyor.
		Item*  item = table->items[index];

		// Table.items dizisindeki indexin kendisini tutuyor.
		// Eğer &item kullanırsak o zaman bu döngüde oluşturulmuş olan değişkenin adresini elde ederiz.
		Item** itemLocation = &table->items[index];


		if (NULL == item)
		{
			return itemLocation;
		}

		if (DELETED == item)
		{
			if (findInsertLocation)
			{
				return itemLocation;
			}

			// We assume deleted items as legitimate items in the table to avoid breaking the chain of double hashing
			// Therefore we continue when we want to locate an item or delete an item
			continue;
		}
		
		const ItemData *data_key = key;
		// if (0 == strncmp((char *)key, (char *)(item->key), data_key->item_size))
		if (0 == memcmp(key, item->key, data_key->item_size))
		{
			if (findInsertLocation)
			{
				freeItem(item);	
			}
			return itemLocation;
		}

		// if (0 == strcmp(key, item->key))
		// {
		// 	return itemLocation;
		// }


		// There is no point to compare keys if we want to find an empty slot
		if (findInsertLocation)
		{
			continue;
		}
	}
}
static void resize(Table* table, int newSize)
{
	if (newSize < 50)
	{
		return;
	}

	// Allocate a new table, and copy item pointers
	Table* newTable = allocTable(newSize);
	for (int i = 0; i < table->size; i++)
	{
		Item* item = table->items[i];
		
		// If an item is deleted or null, skip it
		if (NULL == item || DELETED == item)
		{
			continue;
		}

		Insert(newTable, item->key, item->value);
	}

	// Copy the final amount of count to new table
	table->count = newTable->count;

	// Swap tables so we can free memory on new table pointer
	int tempSize = table->size; 
	table->size = newTable->size;
	newTable->size = tempSize;

	Item** tempItems = table->items;
	table->items = newTable->items;
	newTable->items = tempItems;

	// The strategy is we modify the table passed as argument
	// And free the new table with swapped memory locations
	FreeTable(newTable);
}

// Public methods
Table* AllocTable()
{
	return allocTable(50);
}
void FreeTable(Table* table)
{
	for (int i = 0; i < table->size; i++)
	{
		Item* item = table->items[i];
		freeItem(item);
	}

	free(table->items);
	free(table);
}
void Insert(Table* table, const void* key, const void* value)
{
	// Basit stack yapısı, yüzde cinsinden kullanımına bakıyormuş.
	if (70 < table->count * 100 / table->size)
	{
		resize(table, table->size * 2);
 	}

	// Search an empty slot location to insert the new item
	Item** itemLocation = search(table, key, true);
	(*itemLocation) = allocItem(key, value);

	// Increase the count of items in the table
	table->count++;
}
void Delete(Table* table, const void* key)
{
	Item** itemLocation = search(table, key, false);
	Item*  item = *itemLocation;

	// If search returned an empty slot location, we do nothing, this item doesn't exist in table already
	if (NULL == item)
	{
		return;
	}

	// item aldıktan sonra deleted olarak işaretliyor.
	freeItem(item);
	*itemLocation = DELETED;

	table->count--;

	// Basit stack yapısı, yüzde cinsinden kullanımına bakıyormuş.
	if (10 > table->count * 100 / table->size)
	{
		resize(table, table->size / 2);
	}
}

// void* Search(Table* table, const void* key)
Item *Search(Table* table, const void* key)
{
	// Search for the item with the given key
	Item** itemLocation = search(table, key, false);
	Item*  item = *itemLocation;
	if (NULL == item)
	{
		return NULL;
	}

	// Return the value of the item found
	// return item->value;

	// Return the item found
	return item;
}