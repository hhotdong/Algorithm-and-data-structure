#include <stdio.h>
#include "circular_linked_list.h"

int main(void)
{
    List list;
    int data, i, nodeNum;
    ListInit(&list);

    ListInsert(&list, 3);
    ListInsert(&list, 4);
    ListInsert(&list, 5);
    ListInsertFront(&list, 2);
    ListInsertFront(&list, 1);

    if (ListFirst(&list, &data))
    {
        printf("%d ", data);

        for (i = 0; i < ListCount(&list) * 3 - 1; ++i)
        {
            if (ListNext(&list, &data))
                printf("%d ", data);
        }
    }
    printf("\n");

    printf("Remove multiples of two.\n");
    nodeNum = ListCount(&list);
    if (nodeNum != 0)
    {
        ListFirst(&list, &data);
        
        if (data % 2 == 0)
            ListRemove(&list);
        
        for (i = 0; i < nodeNum - 1; ++i)
        {
            ListNext(&list, &data);
            if (data % 2 == 0)
                ListRemove(&list);
        }
    }

    if (ListFirst(&list, &data))
    {
        printf("%d ", data);

        for (i = 0; i < ListCount(&list) - 1; ++i)
        {
            if (ListNext(&list, &data))
                printf("%d ", data);
        }
    }
    printf("\n");

    return 0;
}
