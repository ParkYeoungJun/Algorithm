#include <cstdio>
#include <iostream>
#include <malloc.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)

using namespace std;

int N, T;
int len[16];
int sum[1 << 16];
int half[1 << 16];

void quicksort(int *data, int start, int end)
{
    if (start >= end)
    {
        // 원소가 1개인 경우
        return;
    }

    int pivot = start;
    int i = pivot + 1;
    int j = end;
    int temp;

    while (i <= j)
    {
        while (i <= end && data[i] <= data[pivot])
        {
            i++;
        }
        while (j > start && data[j] >= data[pivot])
        {
            j--;
        }

        if (i > j)
        {
            // 엇갈림
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }
        else
        {
            // i번째와 j번째를 스왑
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    quicksort(data, start, j - 1);
    quicksort(data, j + 1, end);
}

int main()
{
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &N);

        for (int i = 0; i < N; ++i)
            scanf("%d", &len[i]);

        //quicksort(len, 0, N - 1);

        int k = (1 << N) - 1;

        for (int i = 1; i <= k; ++i)
        {
            sum[i] = 0;
            half[i] = false;
        }

        for (int i = 1; i <= k; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                // 모든 경우
                if (i & (1 << j))
                {
                    sum[i] += len[j];
                }
            }
        }

        for (int i = 1; i <= k; ++i)
        {
            // 홀수
            if (sum[i] & 1)
                continue;

            // 부분중에 반이되는게 있을 때
            for (int j = i; j; j = ((j - 1) & i))
            {
                if (sum[j] == (sum[i] / 2))
                {
                    half[i] = true;
                    break;
                }
            }
        }

        int ans = 0;
        for (int i = k; i; i = ((i - 1) & k))
        {
            int x = (~i & k);
            if (half[i] && half[x])
            {
                ans = max(ans, sum[i] * sum[x] / 4);
            }
        }

        printf("%d\n", ans);
    }
}