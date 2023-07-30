#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubly_linked_list.h"

typedef struct _userData {
    char name[64];
    char number[64];
} UserData;

void PrintList(List * pList)
{
    if (ListCount(pList) < 1)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Print list: count(%d), pHead(%p)\n", pList->numOfData, pList->head);

    UserData * pUser = NULL;
    if (ListFirst(pList, (void**)&pUser))
    {
        printf("Name(%s)\tNumber(%s)\n", pUser->name, pUser->number);
        
        while (ListNext(pList, (void**)&pUser))
            printf("Name(%s)\tNumber(%s)\n", pUser->name, pUser->number);
    }
}

void PrintListReversely(List * pList)
{
    UserData * pUser = NULL;
    while (ListNext(pList, (void**)&pUser))
        ;

    printf("Print list: count(%d), pHead(%p)\n", pList->numOfData, pList->head);
    
    pUser = pList->cur->pData;
    printf("Name(%s)\tNumber(%s)\n", pUser->name, pUser->number);

    while (ListPrevious(pList, (void**)&pUser))
        printf("Name(%s)\tNumber(%s)\n", pUser->name, pUser->number);
}

const char * GetUserDataKey(void * pUser)
{
    return ((UserData *)pUser)->name;
}

UserData * CreateUser(const char * name, const char * number)
{
    UserData * pUser = (UserData*)malloc(sizeof(UserData));
    strlcpy(pUser->name  , name  , sizeof(pUser->name));
    strlcpy(pUser->number, number, sizeof(pUser->number));
    return pUser;
}

int main(void)
{
    List list = { 0 };
    ListInit(&list, GetUserDataKey);

    printf("Insert 4 users at rear\n");
    ListInsert(&list, CreateUser("Mario"  , "000-000-0000"));
    ListInsert(&list, CreateUser("Peach"  , "111-111-1111"));
    ListInsert(&list, CreateUser("Kong"   , "222-222-2222"));
    ListInsert(&list, CreateUser("Bowser" , "333-333-3333"));
    PrintList(&list);
    printf("-------------------------------------------------\n");

    printf("Insert new user at index 2\n");
    ListInsertAt(&list, CreateUser("Luigi", "444-444-4444"), 2);
    PrintList(&list);
    printf("-------------------------------------------------\n");

    UserData * pUser = ListGetAt(&list, 1)->pData;
    printf("Get User at index 1: Name(%s) \tNumber(%s)\n", pUser->name, pUser->number);
    pUser = ListGetAt(&list, 3)->pData;
    printf("Get User at index 3: Name(%s) \tNumber(%s)\n", pUser->name, pUser->number);
    printf("-------------------------------------------------\n");

    printf("Insert 2 users at front\n");
    ListInsertFront(&list, CreateUser("Goomba", "555-555-5555"));
    ListInsertFront(&list, CreateUser("Yoshi" , "666-666-6666"));
    PrintList(&list);
    printf("-------------------------------------------------\n");

    printf("Print reversely\n");
    PrintListReversely(&list);
    printf("-------------------------------------------------\n");

    printf("Find key: Mario\n");
    Node * pTargetNode = ListFindNode(&list, "Mario");
    if (pTargetNode != NULL)
        printf("Found: %s\n", ((UserData*)(pTargetNode->pData))->number);
    else
        printf("Not found\n");

    printf("\n");

    printf("Find key: KrankyKong\n");
    pTargetNode = ListFindNode(&list, "KrankyKong");
    if (pTargetNode != NULL)
        printf("Found: %s\n", ((UserData*)(pTargetNode->pData))->number);
    else
        printf("Not found\n");

    printf("\n");

    printf("Remove user: Mario\n");
    ListRemoveNode(&list, "Mario");
    printf("\n");
    
    printf("Find key: Mario\n");
    pTargetNode = ListFindNode(&list, "Mario");
    if (pTargetNode != NULL)
        printf("Found: %s\n", ((UserData*)(pTargetNode->pData))->number);
    else
        printf("Not found\n");
    printf("-------------------------------------------------\n");
    
    printf("Remove all elements\n");
    while (ListFirst(&list, (void**)&pUser))
        free(ListRemove(&list));
    PrintList(&list);
    printf("-------------------------------------------------\n");
    
    printf("Insert 2 users at rear\n");
    ListInsert(&list, CreateUser("DiddyKong", "777-777-7777"));
    ListInsert(&list, CreateUser("Toad"     , "888-888-8888"));
    PrintList(&list);
    printf("-------------------------------------------------\n");
    
    printf("Release list\n");
    ListRelease(&list);
    PrintList(&list);
    printf("-------------------------------------------------\n");

    printf("Insert 2 users at rear\n");
    ListInsert(&list, CreateUser("DiddyKong", "777-777-7777"));
    ListInsert(&list, CreateUser("Toad"     , "888-888-8888"));
    PrintList(&list);
    printf("-------------------------------------------------\n");

    printf("Release list\n");
    ListRelease(&list);
    PrintList(&list);
    printf("-------------------------------------------------\n");
    
    return 0;
}

