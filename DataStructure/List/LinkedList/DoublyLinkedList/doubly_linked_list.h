#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#define TRUE  1
#define FALSE 0

typedef struct _node
{
    void * pData;
    struct _node * next;
    struct _node * prev;
} Node;

typedef struct _doublyLinkedList
{
    Node * head;
    Node * tail;
    Node * cur;
    int numOfData;
    const char * (*pfGetKey) (void *);
} DoublyLinkedList;

typedef DoublyLinkedList List;

void ListInit(List * plist, const char * (*pfGetKey)(void *));

void ListRelease(List * pList);

void ListInsert(List * pList, void * pData);

void ListInsertFront(List * pList, void * pData);

int ListInsertAt(List * pList, void * pData, int idx);

Node * ListFindNode(List * pList, const char * pKey);

Node * ListGetAt(List * pList, int idx);

int ListFirst(List * pList, void ** pData);

int ListNext(List * pList, void ** pData);

int ListPrevious(List * pList, void ** pData);

void * ListRemove(List * pList);

int ListRemoveNode(List * pList, const char * pKey);

int ListCount(List * pList);

#endif  // _DOUBLY_LINKED_LIST_H_
