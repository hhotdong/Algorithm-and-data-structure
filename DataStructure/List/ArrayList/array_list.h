#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_

#define FALSE 0
#define TRUE 1
#define MAX_LEN 100

typedef int LData;

typedef struct _ArrayList
{
    LData arr[MAX_LEN];
    int numOfData;
    int curPos;
} ArrayList;

typedef ArrayList List;

void ListInit(List* plist);

void ListAdd(List* plist, LData data);

LData ListRemove(List* plist);

int ListFirst(List* plist, LData* pdata);

int ListNext(List* plist, LData* pdata);

int ListCount(List* plist);

int ListIsEmpty(List* plist);

#endif
