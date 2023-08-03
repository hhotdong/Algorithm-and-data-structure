// https://www.computerenhance.com/p/the-four-programming-questions-from?triedSigningIn=true
#include <stdio.h>

void CopyString(char * from, char * to)
{
    int i = 0;
    char * cur = from;
    while (*(cur + i) != '\0')
    {
        *(to + i) = *(cur + i);
        ++i;
    }
    *(to + i) = '\0';
}

void TestCopyString()
{
    char nameA[20] = "hhot";
    char nameB[20] = { 0 };
    
    printf("nameA: %s\n", nameA);
    printf("nameB: %s\n", nameB);

    printf("Copy nameA to nameB.\n");
    CopyString(nameA, nameB);

    printf("nameA: %s\n", nameA);
    printf("nameB: %s\n", nameB);
}

int main(void)
{
    TestCopyString();
    return 0;
}
