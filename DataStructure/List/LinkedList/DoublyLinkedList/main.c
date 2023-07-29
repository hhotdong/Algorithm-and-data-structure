#include <stdio.h>
#include "doubly_linked_list.h"

void PrintList(List * plist)
{
    if (ListCount(plist) < 1)
    {
        printf("List is empty!\n");
        return;
    }

    Data data;
    if (ListFirst(plist, &data))
    {
        printf("%d ", data);
        
        while (ListNext(plist, &data))
            printf("%d ", data);
        printf("\n\n");
    }
}

int main(void)
{
    List list;
    Data data;
    ListInit(&list);

    printf("Insert numbers(1~6) at front\n");
    ListInsertFront(&list, 1); ListInsertFront(&list, 2);
    ListInsertFront(&list, 3); ListInsertFront(&list, 4);
    ListInsertFront(&list, 5); ListInsertFront(&list, 6);
    PrintList(&list);

    printf("Insert number 7 at index 1\n"); ListInsertAt(&list, 7, 1);
    printf("Insert number 8 at index 3\n"); ListInsertAt(&list, 8, 3);
    PrintList(&list); 
    
    printf("Get number at index 1: %d\n", ListGetAt(&list, 1)->data);
    printf("Get number at index 3: %d\n", ListGetAt(&list, 3)->data);
    printf("Get number at index 5: %d\n", ListGetAt(&list, 5)->data);
    printf("\n");

    printf("Remove number 3\n");
    if (ListFirst(&list, &data))
    {
        if (data == 3)
            ListRemove(&list);
        else
        {
            while (ListNext(&list, &data))
            {
                if (data == 3)
                {
                    ListRemove(&list);
                    break;
                }
            }
        }
    }
    PrintList(&list);

    printf("Insert numbers(9~11) at rear\n");
    ListInsert(&list, 9); ListInsert(&list, 10);
    ListInsert(&list, 11);
    PrintList(&list);

    printf("Iterate reversely\n");
    printf("%d ", list.cur->data);
    while (ListPrevious(&list, &data))
        printf("%d ", data);
    printf("\n\n");

    printf("Remove all\n");
    while (ListFirst(&list, &data))
        ListRemove(&list);
    PrintList(&list);
    printf("\n");

    printf("Insert numbers(1~3)\n");
    ListInsert(&list, 1); ListInsert(&list, 2);
    ListInsert(&list, 3);
    PrintList(&list);

    printf("Remove all\n");
    while (ListFirst(&list, &data))
        ListRemove(&list);
    PrintList(&list);
    printf("\n");

    return 0;
}

