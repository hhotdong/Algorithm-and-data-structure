#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CNT_ALPHABET 26

bool IsInOrder(char* str) {
    for (int i = 1; i < strlen(str); ++i) {
        if (str[i - 1] > str[i])
            return false;
    }
    return true;
}

void Print(char str[], int curIdx, int endIdx) {
    if (curIdx > endIdx) {
        if (IsInOrder(str))
            printf("%s\n", str);
        return;
    }

    for(int c = 'a'; c <= 'z'; ++c) {
        str[curIdx] = c;
        Print(str, curIdx + 1, endIdx);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Expected input format: alphabet_variation number\n");
        return 1;
    }

    int num = atoi(argv[1]);
    if (num < 1 || num > CNT_ALPHABET) {
        printf("Command line argument must be in range(number > 0 && number <= 26).\n");
        return -1;
    }

    char str[CNT_ALPHABET];
    Print(str, 0, num - 1);

    return 0;
}
