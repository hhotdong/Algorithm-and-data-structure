// 참고: 윤성우의 열혈 자료구조
#include <stdio.h>
#include "array_list.h"

void ListInit(List* plist)
{
    (plist->numOfData) = 0;
    (plist->curPos) = -1;
}

void ListAdd(List* plist, LData data)
{
    if (plist->numOfData >= MAX_LEN)
        return;
    
    plist->arr[plist->numOfData] = data;
    ++(plist->numOfData);
}

LData ListRemove(List* plist)
{
    if (ListIsEmpty(plist))
        return -1;

    LData delData = plist->arr[plist->curPos];
    
    for (int i = plist->curPos; i < plist->numOfData - 1; ++i)
        plist->arr[i] = plist->arr[i + 1];
    
    --(plist->numOfData);
    --(plist->curPos);
    return delData;
}

int ListFirst(List* plist, LData* pdata)
{
    if (ListIsEmpty(plist))
        return FALSE;

    (plist->curPos) = 0;
    *pdata = plist->arr[0];
    return TRUE;
}

int ListNext(List* plist, LData* pdata)
{
    if ((plist->curPos) + 1 >= (plist->numOfData))
        return FALSE;
    
    ++(plist->curPos);
    *pdata = plist->arr[plist->curPos];
    return TRUE;
}

int ListCount(List* plist)
{
    return plist->numOfData;
}

int ListIsEmpty(List* plist)
{
    return plist->numOfData == 0;
}
