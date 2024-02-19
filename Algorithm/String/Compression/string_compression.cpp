// Credit: 홍정모 교수님의 <자료구조 압축코스>
#include <iostream>

void InsertionSort(char arr[], int len)
{
    for (int i = 1; i < len; ++i)
    {
        int j = i;
        char key = arr[j];
        for (; j > 0 && arr[j - 1] > key; --j)
            arr[j] = arr[j - 1];
        arr[j] = key;
    }
}

int Count(char* arr, int len, char x)
{
    int cnt = 0;
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] == x)
            ++cnt;
    }
    return cnt;
}

int SequentialSearch(char* arr, int len, char x)
{
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int SortedCountHelper(char* arr, int len, char x, int start)
{
    int cnt = 0;
    for (int i = start; i < len; ++i)
    {
        if (arr[i] == x)
            ++cnt;
        else
            break;
    }
    return cnt;
}

int SortedCount(char* arr, int len, char x)
{
    int i = SequentialSearch(arr, len, x);

    if (i >= 0)
        return SortedCountHelper(arr, len, x, i + 1) + 1;
    else
        return 0;
}

int main(void)
{
    char s[] = "sdfkuzpcupzxczasdwqbbczx";
    int n = sizeof(s) - 1;

    assert(n >= 1);

    // 1. 직접 출력하는 방법
    for (int i = 0; i < 26; ++i)
    {
        char c = 'a' + i;
        int cnt = Count(s, n, c);
        if (cnt > 0)
            std::cout << c << cnt << std::flush;
    }
    std::cout << std::endl;

    // 2. 테이블에 저장 후 나중에 출력하는 방법
    int table[26] = { 0 };
    for (int i = 0; i < 26; ++i)
    {
        char c = 'a' + i;
        int cnt = Count(s, n, c);
        if (cnt > 0)
            table[i] = cnt;
    }

    for (int i = 0; i < 26; ++i)
    {
        if (table[i] == 0)
            continue;
        std::cout << char('a' + i) << table[i];
    }
    std::cout << std::endl;

    // 3. 정렬 후 직접 출력하는 방법
    InsertionSort(s, n);
    std::cout << s << std::endl;

    char c = s[0];
    int count = 1;

    std::cout << c;

    for (int i = 1; i < n; ++i)
    {
        if (s[i] == c)
            ++count;
        else
        {
            std::cout << count << std::flush;
            c = s[i];
            count = 1;
            std::cout << c << std::flush;
        }
    }
    std::cout << count << std::endl;

    // 4. 정렬 후 함수 이용하는 방법
    for (int i = 0; i < 26; ++i)
    {
        int cnt = SortedCount(s, n, 'a' + i);
        if (cnt > 0)
            std::cout << char('a' + i) << cnt << std::flush;
    }
    std::cout << std::endl;

    return 0;
}
