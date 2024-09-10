#include <stdio.h>
#include <string.h>
#include <math.h>

#include "hashtable.h"
#include "MyTypes.h"


// git commit icin


int main(int argc, char **argv)
{
	Table *table = AllocTable();

	// Test Code
	int keys[10] = {47, 15, 28, 61, 5, 36, 12, 19, 3, 22};
    int vals[10] = {82, 93, 74, 90, 53, 67, 84, 41, 76, 8};


	// Insert
	for (int i = 0; i < 10; i++)
	{
		Integer key = {data_int, keys[i]};
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





// Ockis Hocma Test
// int main()
// {
// 	// Dirty testing

// 	// 47 tane Item *
// 	Table* table = AllocTable();
// #define SZ 55
// 	// const int sz = SZ;
// 	// char value[SZ];

// 	struct tagValue{
// 		ItemData data;
// 		int sz;
// 		char values[SZ];
// 	} value = {{0, sizeof(struct tagValue)}, SZ};

// 	const int test = value.sz;

// 	// Inserting all items should be no problem
// 	for (int i = 0; i < test; i++)
// 	{
// 		sprintf_s(value.values, value.sz, "%d", i);
// 		Insert(table, value.values, value.values);
// 	}

// 	// All items should exist
// 	for (int i = 0; i < test; i++)
// 	{
// 		sprintf_s(value.values, value.sz, "%d", i);
// 		if (NULL == Search(table, value.values))
// 		{
// 			printf("assertion failed. shouldn't reach here");
// 			gets_s(value.values, 4);
// 		}
// 	}

// 	// All items can be deleted without problem
// 	for (int i = 0; i < test; i++)
// 	{
// 		sprintf_s(value.values, value.sz, "%d", i);
// 		Delete(table, value.values);
// 	}

// 	// All items should not exist at this point
// 	for (int i = 0; i < test; i++)
// 	{
// 		sprintf_s(value.values, value.sz, "%d", i);
// 		if (NULL != Search(table, value.values))
// 		{
// 			printf("assertion failed. shouldn't reach here");
// 			gets_s(value.values, 4);
// 		}
// 	}

// 	FreeTable(table);
// 	return 0;
// }