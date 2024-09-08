#include <stdio.h>
#include <string.h>
#include <math.h>

#include "hashtable.h"
#include "MyTypes.h"



void al_bu_itemi_kullan(Item *item);


int main(int argc, char **argv)
{
	Table *table = AllocTable();


	char keys[10][20] = {
		"Gokkusagi", "Kitap", "Kumsal", "Damlacik", "Papatya", "Zaman", "Bulut", "Deniz", "Ruzgar", "Yagmur"
	};
	char values[10][20] = {
		"Ayna", "Yildiz", "Kahve", "Kalem", "Nehir", "Yokus", "Cicek", "Marti", "Masal", "Huzur"
	};

	ItemData item_str = {STRING, sizeof(String)};

	// Insert
	for (int i = 0; i < 10; i++)
	{
		String str_key = {item_str, keys[i]}; 
		String str_val = {item_str, values[i]};

		Insert(table, &str_key, &str_val);
	}
	printf("table count : %d\n", table->count);

	// Print
	for (int i = 0; i < 10; i++)
	{
		String str_key = {item_str, keys[i]};

		Item *item = Search(table, &str_key);
		if (NULL == item)
		{

		}
		else
		{
			if (item->type_key == STRING && item->type_value == STRING)
			{
				String *strp_key = (String *)item->key;
				String *strp_val = (String *)item->value;
				printf("%s : %s\n", strp_key->text, strp_val->text);
			}
		}
	}


	FreeTable(table);
	

	return 0;
}


void al_bu_itemi_kullan(Item *item)
{
	if (item == NULL)
	{
		printf("bu nasil bi keydir listede yoktur.\n");		
	}
	else if (item->type_key == STRING)
	{
		printf("Bu key bir string\n");
		String *key = item->key;
		String *value = item->value;

		printf("key : %s\n", key->text);
		printf("value : %s\n", value->text);
	}
	else if (item->type_key == INT)
	{
		printf("Bu key bir integeyr\n");
	}
	else
	{
	}
}

// enum {INT, FLOAT, STRING, STRING64, CHAR, BOOLEAN};

// struct Integer {
// 	ItemData data;
// 	int value;
// };

// struct String {
// 	ItemData data;
// 	size_t length;
// 	char *text;
// };

// struct StringStatic_64 {
// 	ItemData data;
// 	char text[64];
// };


// void my_insert(const char *key, const char *value);


// int denek_main(int argc, char **argv)
// {
// 	ItemData item_int = {INT, sizeof(struct Integer)};
// 	ItemData item_str = {STRING, sizeof(struct String)};
// 	ItemData item_strs_64 = {STRING64, sizeof(struct StringStatic_64)};
	
	

// 	(struct Integer){item_int, 7};
// 	(struct Integer){item_int, 78};
// 	(struct Integer){item_int, 55};
// 	(struct Integer){item_int, 3};

// 	(struct String){item_str, 30, "Deneme Metnini"};
// 	(struct String){item_str, 3, "Dunya"};
// 	(struct String){item_str, 50, "Gule GUle DUnya"};
// 	(struct String){item_str, 20, "Merhaba DUnya"};
	
	

// 	my_insert(&(struct Integer){item_int, 78}, &(struct String){item_str, 20, "Merhaba DUnya"});


// 	return 0;
// }


// void my_insert(const char *key, const char *value)
// {
// 	ItemData *data_key = (ItemData *)key, *data_value = (ItemData *)value;


// 	printf("key type : %d, size : %u\n", data_key->type, data_key->item_size);
// 	printf("value type : %d, size : %u\n", data_value->type, data_value->item_size);


// 	switch (data_key->type)
// 	{
// 	case INT:
// 		printf("key value : %d\n", ((struct Integer *)key)->value);
// 		break;
	
// 	case STRING:
// 		struct String *str = key;
// 		printf("key value : %s size : %u\n", str->text, str->length);
// 		break;
	
// 	default:
// 		break;
// 	}


// 	switch (data_value->type)
// 	{
// 	case INT:
// 		printf("value value : %d\n", ((struct Integer *)value)->value);
// 		break;

// 	case STRING:
// 		struct String *str = value;
// 		printf("value value : %s size : %u\n", str->text, str->length);
// 		break;
	
// 	default:
// 		break;
// 	}

// }


// enum {
// 	STRING,
// 	INT,
// 	FLOAT,
// 	STRUCT,
// 	NUM
// };


// typedef struct tagStruct
// {
// 	int a;
// 	float b;
// 	char *c;
// } Struct;


// typedef struct tagNum {
// 	int num;
// } Num;


// int um_main(int argc, char **argv)
// {
	// Table *table = AllocTable();

	// // Insert
	// Insert(table, &(int){6}, "Alti", STRING);
	// Insert(table, "Merhaba", "Nasilsin", STRING);
	// Insert(table, &(float){78.34}, &(int){304}, INT);

	// Num num = {7};
	// Struct denek = {55, 90.55, "Denemek Icin Struct"};
	// Insert(table, &num, &denek, STRUCT);

	// Insert(table, &(int){66}, &num, NUM);


	// Search
	// Item *item = Search(table, "Merhaba");
	// Item *item = Search(table, &num);
	// Item *item = Search(table, &(int){66});
	// Item *item = Search(table, &(int){6});
	// Item *item = Search(table, &(float){78.34});

	// if (item == NULL)
	// {
	// 	printf("item is not found\n");
	// }
	// else if (item->value_type == STRING)
	// {
	// 	printf("Bu bir string %s\n", item->value);
	// }
	// else if (item->value_type == STRUCT)
	// {
	// 	Struct *d = item->value;
	// 	printf("Bu bir struct a : %d, b : %f, c : %s\n", d->a, d->b, d->c);
	// }
	// else if (item->value_type == NUM)
	// {
	// 	Num *n = item->value;
	// 	printf("Bu bir num ve num : %d\n", n->num);
	// }
	// else if (item->value == FLOAT)
	// {
	// 	float f = *(float *)item->value;
	// 	printf("Bu bir float : %f\n", f);
	// }
	// else if (item->value_type == INT)
	// {
	// 	printf("Bu bir int : %d\n", *(int *)item->value);
	// }

	// FreeTable(table);

// 	return 0;
// }


// int ock_main()
// {
// 	// Dirty testing

// 	// 47 tane Item *
// 	Table* table = AllocTable();
// #define SZ 55
// 	const int sz = SZ;
// 	char value[SZ];
// 	const int test = sz;

// 	// Inserting all items should be no problem
// 	for (int i = 0; i < test; i++)
// 	{
// 		sprintf_s(value, sz, "%d", i);
// 		Insert(table, value, value);
// 	}

// 	// All items should exist
// 	for (int i = 0; i < test; i++)
// 	{
// 		sprintf_s(value, sz, "%d", i);
// 		if (NULL == Search(table, value))
// 		{
// 			printf("assertion failed. shouldn't reach here");
// 			gets_s(value, 4);
// 		}
// 	}

// 	// All items can be deleted without problem
// 	for (int i = 0; i < test; i++)
// 	{
// 		sprintf_s(value, sz, "%d", i);
// 		Delete(table, value);
// 	}

// 	// All items should not exist at this point
// 	for (int i = 0; i < test; i++)
// 	{
// 		sprintf_s(value, sz, "%d", i);
// 		if (NULL != Search(table, value))
// 		{
// 			printf("assertion failed. shouldn't reach here");
// 			gets_s(value, 4);
// 		}
// 	}

// 	FreeTable(table);
// 	return 0;
// }