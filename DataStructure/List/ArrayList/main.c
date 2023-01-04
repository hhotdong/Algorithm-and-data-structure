#include <stdio.h>
#include "array_list.h"

int main(void)
{
    List list;
    LData data;
    InitList(&list);
    Add(&list, 1);
    Add(&list, 3);
    Add(&list, 5);

    PrintList(&list);
    First(&list, &data);
    Next(&list, &data); 
    Next(&list, &data); 
    Remove(&list);
    printf("\n");

    PrintList(&list);
    Remove(&list);
    printf("\n");

    PrintList(&list);
    Remove(&list);
    printf("\n");

    PrintList(&list);
    Remove(&list);
    printf("\n");

    LData delData;
    if (First(&list, &delData))
    {
        Remove(&list);
        while (Next(&list, &delData))
            Remove(&list);
    }
    
    return 0;
}
