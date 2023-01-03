#ifndef _H_ARRAY_LIST_
#define _H_ARRAY_LIST_

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

void InitList(List* plist);

void Add(List* plist, LData data);

void Remove(List* plist, LData data);

int First(List* plist, LData* pdata);

int Next(List* plist, LData* pdata);

int Count(List* plist);

int IsEmpty(List* plist);

int Search(List* plist, LData data);

#endif
