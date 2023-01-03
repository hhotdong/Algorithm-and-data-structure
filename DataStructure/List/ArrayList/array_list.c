// WIP
#include <stdio.h>

#define MAX_LEN 100

typedef int LData;

typedef struct _ArrayList
{
    LData arr[MAX_LEN];
    int numOfData;
} ArrayList;

typedef ArrayList List

void InitializeList(List* list)
{
    list.numOfData = 0;
}

void Add(List* list, LData data)
{
    if (IsFull(list))
        return;

    list.arr[numOfData++] = data;
}

void Remove(List* list, LData data)
{
    if (IsEmpty(list))
        return;

    for (int i = 0; i < numOfData; ++i)
    {
        if (list.arr[i] == data)
        {
            for (int j = i; j < numOfData - 1; ++j)
                list.arr[j] = list.arr[j + 1];
            --numOfData;
            break;
        }
    }
}

bool IsFull(List* list)
{
    return list.numOfData >= MAX_LEN;
}

bool IsEmpty(List* list)
{
    return list.numOfData == 0;
}

bool Search(List* list, LData data)
{
    if (IsEmpty(list))
        return false;

    for (int i = 0; i < numOfData; ++i)
    {
        if (list.arr[i] == data)
            return true;
    }
    return false;
}
