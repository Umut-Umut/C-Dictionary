#pragma once


#include "Item.h"


typedef struct
{
	int size;
	int count;
	Item** items;
}
Table;


void Insert(Table* table, const void* key, const void* value);
void Delete(Table* table, const void* key);
Item *Search(Table* table, const void* key);
void* ock_Search(Table* table, const void* key);
Table* AllocTable();
void FreeTable(Table* table);