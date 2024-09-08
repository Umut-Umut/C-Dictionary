#pragma once


#include "Item.h"


typedef struct
{
	int size;
	int count;
	Item** items;
}
Table;


void Insert(Table* table, const char* key, const char* value);
void Delete(Table* table, const char* key);
Item *Search(Table* table, const char* key);
char* ock_Search(Table* table, const char* key);
Table* AllocTable();
void FreeTable(Table* table);