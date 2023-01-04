#include "array_list.h"

void InitList(List* plist)
{
    plist->numOfData = 0;
    plist->curPos = 0;
}

void Add(List* plist, LData data)
{
    if (plist->numOfData >= MAX_LEN)
        return;
    
    plist->arr[plist->numOfData] = data;
    ++(plist->numOfData);
}

LData Remove(List* plist)
{
    if (IsEmpty(plist))
        return -1;

    LData delData = plist->arr[plist->curPos];
    
    for (int i = plist->curPos; i < plist->numOfData - 1; ++i)
        plist->arr[i] = plist->arr[i + 1];
    
    --(plist->numOfData);
    --(plist->curPos);
    return delData;
}

int First(List* plist, LData* pdata)
{
    if (IsEmpty(plist))
        return FALSE;

    plist->curPos = 0;
    *pdata = plist->arr[plist->curPos];
    return TRUE;
}

int Next(List* plist, LData* pdata)
{
    if ((plist->curPos) + 1 >= MAX_LEN)
        return FALSE;
    
    ++(plist->curPos);
    *pdata = plist->arr[plist->curPos];
    return TRUE;
}

int Count(List* plist)
{
    return plist->numOfData;
}

int IsEmpty(List* plist)
{
    return plist->numOfData == 0;
}
