// Creadit: https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>   // atoi()

void Eratos(int num)
{
    if (num < 2) {
        printf("Input number is smaller than two!\n");
        return;
    }
    
    bool prime_number_flags[num];
    for (int i = 0; i < num; i++)
        prime_number_flags[i] = true;
    
    for (int i = 2; i * i <= num; ++i) {
        if (prime_number_flags[i]) {
            for (int j = i * i; j < num; j += i) {
                prime_number_flags[j] = false;
            }
        }
    }
    
    printf("Prime numbers upto %d: ", num);
    
    for (int i = 2; i < num; ++i) {
        if (prime_number_flags[i])
            printf("%d ", i);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Valid input format: eratos number\n");
        exit(1);
    }
    Eratos(atoi(argv[1]));
    return 0;
}
