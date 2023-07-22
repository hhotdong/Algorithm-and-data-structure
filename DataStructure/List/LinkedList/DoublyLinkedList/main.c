#include <stdio.h>
#include "doubly_linked_list.h"

void PrintElements(List * plist)
{
    if (ListCount(plist) < 1)
    {
        printf("List is empty!\n");
        return;
    }

    Data data;
    if (ListFirst(plist, &data))
    {
        printf("Element: %d\n", data);
        
        while (ListNext(plist, &data))
            printf("Element: %d\n", data);
    }
}

int main(void)
{
    List list;
    Data data;
    ListInit(&list);

    printf("Add numbers(1~6)\n");
    ListInsert(&list, 1); ListInsert(&list, 2);
    ListInsert(&list, 3); ListInsert(&list, 4);
    ListInsert(&list, 5); ListInsert(&list, 6);
    PrintElements(&list);
    
    printf("Remove number 3.\n");
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
    PrintElements(&list);

    printf("Add numbers(7~9)\n");
    ListInsert(&list, 7); ListInsert(&list, 8);
    ListInsert(&list, 9);
    PrintElements(&list);

    printf("Iterate reversely.\n");
    printf("Element: %d\n", list.cur->data);
    while (ListPrevious(&list, &data))
        printf("Element: %d\n", data);

    printf("Remove all\n");
    while (ListFirst(&list, &data))
        ListRemove(&list);
    PrintElements(&list);

    printf("Add numbers(1~3)\n");
    ListInsert(&list, 1); ListInsert(&list, 2);
    ListInsert(&list, 3);
    PrintElements(&list);

    printf("Remove all\n");
    while (ListFirst(&list, &data))
        ListRemove(&list);
    PrintElements(&list);

    return 0;
}

