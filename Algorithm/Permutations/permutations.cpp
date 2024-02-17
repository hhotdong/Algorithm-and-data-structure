#include <iostream>

void swap(char& a, char& b)
{
    char tmp = a;
    a = b;
    b = tmp;
}

void Permutations(char * a, const int k, const int m)
{
    if (k == m)
    {
        for (int i = 0; i <= m; i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;
    }
    else
    {
        for (int i = k; i <= m; i++)
        {
            swap(a[k], a[i]);
            Permutations(a, k+1, m);
            swap(a[k], a[i]);
        }
    }
}

int main(void)
{
    std::cout << "Given array of char: 0, 1, 2, ..., 9" << std::endl;
    std::cout << "Permutation from index 6 to 9" << std::endl;
    char arr[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    Permutations(arr, 6, 9);

    return 0;
}
