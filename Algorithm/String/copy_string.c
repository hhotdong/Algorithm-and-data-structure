// https://www.computerenhance.com/p/microsoft-intern-interview-question-ab7
#include <stdio.h>

void CopyString(char * from, char * to)
{
    // First impl.
    for (int i = 0; to[i] = from[i]; ++i);

    // Second impl. Works samely but results in different ASM than first.
    //while (*to++ = *from++);
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
