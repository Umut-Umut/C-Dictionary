#ifndef ITEM_H
#define ITEM_H


typedef struct tagItemData {
	int type;
	size_t item_size;
} ItemData;

typedef struct
{
	void* key;
	void* value;
    int type_key, type_value;
}
Item;


#endif