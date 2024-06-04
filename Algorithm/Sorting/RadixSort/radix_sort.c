// 윤성우의 <열혈 자료구조>
#include <stdio.h>
#include "../../../DataStructure/Queue/ListBaseQueue/list_base_queue.h"

#define BUCKET_NUM 10

// Radix, 즉 '기수'란 주어진 데이터를 구성하는 기본 요소를 의미한다.
// 예를 들어, 2진수에서는 0과 1이 기수이고 10진수에서는 0부터 9까지의 숫자가 기수가 된다.
// Radix Sort는 비교 연산을 수행하지 않는 정렬 알고리즘이다.
// maxLen: 가장 긴 데이터의 길이 만큼 반복한다.
void RadixSort(int arr[], int num, int maxLen)
{
    Queue buckets[BUCKET_NUM];
    int bi;
    int pos;
    int di;
    int divfac = 1;  // LSD(Least Significant Digit): 첫 번째 자릿수부터 시작해서 정렬함.
    int radix;

    for (bi = 0; bi < BUCKET_NUM; bi++)
        QueueInit(&buckets[bi]);

    for (pos = 0; pos < maxLen; pos++)
    {
        for (di = 0; di < num; di++)
        {
            // N번째 자리의 숫자 추출
            radix = (arr[di] / divfac) % 10;
            Enqueue(&buckets[radix], arr[di]);
        }

        for (bi = 0, di = 0; bi < BUCKET_NUM; bi++)
        {
            while (!QueueIsEmpty(&buckets[bi]))
                arr[di++] = Dequeue(&buckets[bi]);
        }
        divfac *= 10;
    }
}

int main(void)
{
    int arr[7] = { 13, 212, 14, 7141, 10987, 6, 15 };

    int len = sizeof(arr) / sizeof(int);
    int i;

    RadixSort(arr, len, 5);

    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
