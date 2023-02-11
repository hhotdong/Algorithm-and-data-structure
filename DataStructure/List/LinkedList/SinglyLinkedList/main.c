#include <stdio.h>
#include "singly_linked_list.h"

int WhoIsPrecede(int d1, int d2)
{
    if (d1 < d2)
        return 0;
    else
        return 1;
}

int main(void)
{
    List list;
    int data;
    ListInit(&list);

    SetSortRule(&list, WhoIsPrecede);

    ListInsert(&list, 10); ListInsert(&list, 2);
    ListInsert(&list, 44); ListInsert(&list, 33);
    ListInsert(&list, 22);

    // Print elements of list
    if (ListFirst(&list, &data))
    {
         printf("List element: %d\n", data);
         while (ListNext(&list, &data))
             printf("List element: %d\n", data);
    }
   
    printf("Remove 2\n");

    if (ListFirst(&list, &data))
    {
        if (data == 2)
            ListRemove(&list);

        while (ListNext(&list, &data))
        {
            if (data == 2)
                ListRemove(&list);
        }
    }

    if (ListFirst(&list, &data))
    {
        printf("List element: %d\n", data);
        while(ListNext(&list, &data))
           printf("List element: %d\n", data);
    }
    
    printf("\n");
    return 0;
}
