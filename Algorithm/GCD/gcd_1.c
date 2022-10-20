#include <stdio.h>
#include <stdlib.h>  // atoi()

int GCD(int a, int b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main(int argc, char* argv[]) {
    if (argc != 3)
        return 1;

    int num_a = atoi(argv[1]);
    int num_b = atoi(argv[2]);
    if (num_a < 1 || num_b < 1)
        return 1;

    printf("GCD(%d, %d) = %d\n", num_a, num_b, GCD(num_a, num_b));
    return 0;
}
