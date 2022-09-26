#include <stdio.h>
#include <stdlib.h>  // atoi()

int GCD(int a, int b) {
    int gcd = 1;
    int iter_count = a > b ? b : a;
    for (int i = 1; i <= iter_count; ++i) {
        if ((a % i == 0) && (b % i == 0))
            gcd = i;
    }
    return gcd;
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
