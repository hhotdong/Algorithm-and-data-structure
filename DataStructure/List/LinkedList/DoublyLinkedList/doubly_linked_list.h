#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#define TRUE  1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node * next;
    struct _node * prev;
} Node;

typedef struct _doublyLinkedList
{
    Node * head;
    Node * tail;
    Node * cur;
    int numOfData;
} DoublyLinkedList;

typedef DoublyLinkedList List;

void ListInit(List * plist);

void ListInsert(List * plist, Data data);

void ListInsertFront(List * plist, Data data);

int ListInsertAt(List * plist, Data data, int idx);

Node * ListGetAt(List * plist, int idx);

int ListFirst(List * plist, Data * pdata);

int ListNext(List * plist, Data * pdata);

int ListPrevious(List * plist, Data * pdata);

Data ListRemove(List * plist);

int ListCount(List * plist);

#endif  // _DOUBLY_LINKED_LIST_H_
