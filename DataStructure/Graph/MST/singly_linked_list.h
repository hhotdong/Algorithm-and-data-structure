#ifndef _SINGLY_LINKED_LIST_H_
#define _SINGLY_LINKED_LIST_H_

#define TRUE  1
#define FALSE 0

typedef int LData;

typedef struct _node {
    LData data;
    struct _node * next;
} Node;

typedef struct _linkedList {
    Node * head;
    Node * cur;
    Node * prev;
    int numOfData;
    int (*comp)(LData, LData);
} LinkedList;

typedef LinkedList List;

void ListInit(List * plist);

void ListInsert(List * plist, LData data);

int ListFirst(List * plist, LData * pdata);

int ListNext(List * plist, LData * pdata);

LData ListRemove(List * plist);

int ListCount(List * plist);

int ListIsEmpty(List * plist);

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));

#endif  // _SINGLY_LINKED_LIST_H_
