#ifndef _CIRCULAR_LINKED_LIST_H_
#define _CIRCULAR_LINKED_LIST_H_

#define TRUE  1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node * next;
} Node;

typedef struct _CircularLinkedList
{
    Node * tail;
    Node * cur;
    Node * prev;
    int numOfData;
} CircularLinkedList;

typedef CircularLinkedList List;

void ListInit(List * plist);

void ListInsert(List * plist, Data data);

void ListInsertFront(List * plist, Data data);

int ListFirst(List * plist, Data * pdata);

int ListNext(List * plist, Data * pdata);

Data ListRemove(List * plist);

int ListCount(List * plist);

#endif  // _CIRCULAR_LINKED_LIST_H_
