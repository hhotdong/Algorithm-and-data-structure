#include <stdio.h>
#include <stdlib.h>

#define CNT_ALPHABET 26

void Print(char str[], char startChar, int curIdx, int endIdx) {
    if (curIdx > endIdx) {
        printf("%s\n", str);
        return;
    }

    for(int c = startChar; c <= 'z'; ++c) {
        str[curIdx] = c;
        Print(str, c, curIdx + 1, endIdx);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Expected input format: alphabet_variation number\n");
        return 1;
    }

    int num = atoi(argv[1]);
    if (num < 1 || num > CNT_ALPHABET) {
        printf("Command line argument number must be in range(number > 0 && number <= 26).\n");
        return -1;
    }
    char str[CNT_ALPHABET];
    Print(str, 'a', 0, num - 1);

    return 0;
}
