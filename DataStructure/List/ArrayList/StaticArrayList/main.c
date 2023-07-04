// 참고: <윤성우의 열혈 자료구조>
#include <stdio.h>
#include "array_list.h"

void PrintList(List* plist)
{
    LData data;
    printf("List size: %d\n", ListCount(plist));
    if (ListFirst(plist, &data))
    {
        printf("%d ", data);
        while (ListNext(plist, &data))
            printf("%d ", data);
    }
    printf("\n\n");
}

int main(void)
{
    List list;
    LData data;
    ListInit(&list);
    
    for (int i = 1; i <= 10; ++i)
        ListAdd(&list, i);

    PrintList(&list);

    if (ListFirst(&list, &data))
    {
        if (data == 5)
            ListRemove(&list);
        while (ListNext(&list, &data))
        {
            if (data == 5)
                ListRemove(&list);
        }
    }

    PrintList(&list);

    if (ListFirst(&list, &data))
    {
        ListRemove(&list);
        while (ListNext(&list, &data))
            ListRemove(&list);
    }
    
    PrintList(&list);

    return 0;
}
