#include <stdio.h>
#include <string.h>
#include <math.h>

#include "hashtable.h"
#include "MyTypes.h"


int main(int argc, char **argv)
{
	Table *table = AllocTable();



	FreeTable(table);
	

	return 0;
}



// TESTS

/* INTAR TEST
    // 5 adet dinamik tam sayı dizisi oluşturma
    int* keys[5];
	int* vals[5];
    for (int i = 0; i < 5; i++) {
        keys[i] = (int*)malloc(6 * sizeof(int));  // 6 elemanlı dizi
        vals[i] = (int*)malloc(6 * sizeof(int));  // 6 elemanlı dizi
        if (keys[i] == NULL || vals[i] == NULL) {
            printf("Bellek tahsisi basarisiz!\n");
            return 1;
        }
    }

    // Dizilere önceden belirlenmiş sayıları ekleme
    int keys_vals[5][6] = {
        {47, 15, 28, 61, 5, 36},
        {82, 93, 74, 90, 53, 67},
        {12, 19, 3, 22, 84, 41},
        {76, 8, 13, 55, 34, 99},
        {45, 33, 21, 60, 17, 88}
    };
    int vals_vals[5][6] = {
        {12, 34, 56, 78, 90, 11},
        {23, 45, 67, 89, 12, 34},
        {34, 56, 78, 90, 21, 43},
        {45, 67, 89, 12, 32, 54},
        {56, 78, 90, 11, 22, 33}
    };

    // Dizileri doldurma
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            keys[i][j] = keys_vals[i][j];
			vals[i][j] = vals_vals[i][j];
        }
    }


	// Insert
	for (int i = 0; i < 5; i++)
	{
		IntAr key = {data_intar, 6, keys[0]};
		IntAr value = {data_intar, 6, vals[i]};


		Insert(table, &key, &value);
	}
	printf("table count : %d\n", table->count);


	// Print
	for (int i = 0; i < 5; i++)
	{
		printf("\n\n%d.IntAr\n", i);
		IntAr key = {data_intar, 6, keys[i]};

		Item *item = Search(table, &key);
		if (item)
		{
			IntAr *ar_key = (IntAr *)item->key;
			IntAr *ar_val = (IntAr *)item->value;

			for (int j = 0; j < ar_key->length; j++)
			{
				printf("key[%d] = %d", j, ar_key->arr[j]);
				if (j < ar_val->length)
				{
					printf(" : val[%d] = %d\n", j, ar_val->arr[j]);
				}
			}
		}
	}


	// Belleği serbest bırakma
    for (int i = 0; i < 5; i++) {
        free(keys[i]);
		free(vals[i]);
    }
*/

/* INTEGER TEST
	int keys[10] = {47, 15, 28, 61, 5, 36, 12, 19, 3, 22};
    int vals[10] = {82, 93, 74, 90, 53, 67, 84, 41, 76, 8};


	// Insert
	for (int i = 0; i < 10; i++)
	{
		Integer key = {data_int, keys[0]};
		Integer val = {data_int, vals[i]};

		Insert(table, &key, &val);
	}
	printf("table count : %d\n", table->count);

	// Print
	for (int i = 0; i < 10; i++)
	{
		Integer key = {data_int, keys[i]};

		Item *item = Search(table, &key);
		if (item)
		{
			Integer *key = (Integer *)item->key;
			Integer *val = (Integer *)item->value;

			printf("%d : %d\n", key->value, val->value);
			
		}
	}
*/

/* STRING TEST
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
*/


// void al_bu_itemi_kullan(Item *item)
// {
// 	if (item == NULL)
// 	{
// 		printf("bu nasil bi keydir listede yoktur.\n");		
// 	}
// 	else if (item->type_key == STRING)
// 	{
// 		printf("Bu key bir string\n");
// 		String *key = item->key;
// 		String *value = item->value;

// 		printf("key : %s\n", key->text);
// 		printf("value : %s\n", value->text);
// 	}
// 	else if (item->type_key == INT)
// 	{
// 		printf("Bu key bir integeyr\n");
// 	}
// 	else
// 	{
// 	}
// }

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