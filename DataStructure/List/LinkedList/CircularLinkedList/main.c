#include <stdio.h>
#include "circular_linked_list.h"

/*
// NOTE
 P   C
[D]-[0]

    P,C
[D]-[0]

 P   C
[D]-[0]-[1]

     P   C
[D]-[0]-[1]

     C   P
[D]-[0]-[1]
*/

void testInsert(List* list, int n)
{
    printf("Insert %d elements.\n", n);
    for (int i = 0; i < n; ++i)
        ListInsert(list, i);
}

void testInsertFront(List* list, int n)
{
    printf("InsertFront %d elements.\n", n);
    for (int i = 0; i < n; ++i)
        ListInsertFront(list, i);
}

void testPrintAll(List* list)
{
    int data;
    if (ListFirst(list, &data))
    {
        printf("%d ", data);

        for (int i = 0; i < ListCount(list) - 1; ++i)
        {
            if (ListNext(list, &data))
                printf("%d ", data);
        }
    }
    printf("\n");
}

void testClear(List* list)
{
    printf("Clear list.\n");

    int data;
    if (ListFirst(list, &data))
    {
        ListRemove(list);

        while (ListNext(list, &data))
            ListRemove(list);
    }
}

void test1(List* list)
{
    int data, i, nodeNum;
    ListInit(list);

    ListInsert(list, 3);
    ListInsert(list, 4);
    ListInsert(list, 5);
    ListInsertFront(list, 2);
    ListInsertFront(list, 1);

    if (ListFirst(list, &data))
    {
        printf("%d ", data);

        for (i = 0; i < ListCount(list) * 3 - 1; ++i)
        {
            if (ListNext(list, &data))
                printf("%d ", data);
        }
    }
    printf("\n");

    printf("Remove multiples of two.\n");
    nodeNum = ListCount(list);
    if (nodeNum != 0)
    {
        ListFirst(list, &data);
        
        if (data % 2 == 0)
            ListRemove(list);
        
        for (i = 0; i < nodeNum - 1; ++i)
        {
            ListNext(list, &data);
            if (data % 2 == 0)
                ListRemove(list);
        }
    }

    testPrintAll(list);
    testClear(list);
}

void test2(List* list)
{
    testInsert(list, 10);
    testPrintAll(list);
    testClear(list);
  
    testInsertFront(list, 10);
    testPrintAll(list);
    testClear(list);

    testInsert(list, 5);
    testInsertFront(list, 5);
    testPrintAll(list);
    testClear(list);
}

void test3(List* list, int n)
{
    for (int i = 0; i < n+2; ++i)
    {
        testInsert(list, n);
        testPrintAll(list);
        int data;
        if (ListFirst(list, &data))
        {
            if (i == 0)
                ListRemove(list);
            else
            {
                for (int j = 0; j < i; ++j)
                    ListNext(list, &data);
                ListRemove(list);
            }
            printf("Remove after calling ListNext() function %d times.\n", i);
            testPrintAll(list);
        }
        testClear(list);
        printf("\n");
    }
}

int main(void)
{
    List list;
    ListInit(&list);
    
    //test1(&list);
    //printf("\n");

    //test2(&list);
    //printf("\n");

    test3(&list, 1);
    test3(&list, 2);
    test3(&list, 3);
    printf("\n");

    return 0;
}
