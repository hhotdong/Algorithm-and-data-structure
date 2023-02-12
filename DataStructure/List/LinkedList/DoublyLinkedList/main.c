#include <stdio.h>
#include "doubly_linked_list.h"

void PrintElements(List * plist)
{
    if (ListCount(plist) < 1)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Print elements\n");

    Data data;
    ListFirst(plist, &data);
    printf("Element: %d\n", data);
    while (ListNext(plist, &data))
        printf("Element: %d\n", data);
}

int main(void)
{
    List list;
    Data data;
    ListInit(&list);

    ListInsert(&list, 1); ListInsert(&list, 2);
    ListInsert(&list, 3); ListInsert(&list, 4);
    ListInsert(&list, 5); ListInsert(&list, 6);
    ListInsert(&list, 7); ListInsert(&list, 8);

    PrintElements(&list);

    ListFirst(&list, &data);
    ListRemove(&list);
    ListFirst(&list, &data);
    ListRemove(&list);

    PrintElements(&list);

    ListFirst(&list, &data);
    ListRemove(&list);
    for (int i = 0; i < 4; i++)
    {
        ListNext(&list, &data);
        ListRemove(&list);
    }

    PrintElements(&list);

    ListFirst(&list, &data);
    ListRemove(&list);

    PrintElements(&list);

    return 0;
}

