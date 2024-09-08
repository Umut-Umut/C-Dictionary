#ifndef ITEM_H
#define ITEM_H


typedef struct tagItemData {
	int type;
	size_t item_size;
} ItemData;

typedef struct
{
	char* key;
	char* value;
    int type_key, type_value;
}
Item;


#endif