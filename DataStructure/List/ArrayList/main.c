#include <stdio.h>
#include "array_list.h"

int main(void)
{
    List list;
    InitList(&list);
    Add(&list, 1);
    Add(&list, 3);
    Add(&list, 5);

    printf("Count: %d\n", Count(&list));

    Remove(&list);

    printf("Count: %d\n", Count(&list));

    LData delData;
    if (First(&list, &delData))
    {
        Remove(&list);
        while (Next(&list, &delData))
        {
            Remove(&list);
        }
    }

    return 0;
}
