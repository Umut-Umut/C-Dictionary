#ifndef MY_TYPE_H
#define MY_TYPE_H


#include "Item.h"


enum {INT, STRING, FLOAT, CHAR, BOOLEAN, LONG, INTU, INTARR, INTARR_S64};


typedef struct tagIteger {
    ItemData data;
    int value;
} Integer;

typedef struct tagFloat {
    ItemData data;
    float value;
} Float;

typedef struct tagIntArray {
    ItemData data;
    int *arr;
} IntArray;

typedef struct tagIntArrayStatic
{
    ItemData data;
    int arr[64];
} IntArray_S64;

typedef struct tagString {
    ItemData data;
    char *text;
} String;


typedef struct tagString64 {
    ItemData data;
    char text[64];
} String64;


// ItemData data_str = {STRING, sizeof(String)};


#endif