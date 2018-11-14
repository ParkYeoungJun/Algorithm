#include <cstdio>
#include <iostream>

using namespace std;

int B, N;

int SHIP[15];
int PEOPLE[100005];

int DP[1 << 10];


inline int max(int a, int b) { return a > b ? a : b;}

int main()
{

    scanf("%d %d", &B, &N);

    for (int i = 0; i < B; i++)
        scanf("%d", &SHIP[i]);

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &PEOPLE[i]);
        PEOPLE[i] += PEOPLE[i - 1];
    }

    int res = -1;

    for (int i = 1; i < (1 << B); i++)
    {
        int n = 0, remain = 0;
        for (int j = 0; j < B; j++)
        {
            int mask = 1 << j;

            if (i & mask)
            {
                int last = PEOPLE[DP[i ^ mask]];

                int l = 0, h = N+1, target = last + SHIP[j];
                while (l < h)
                {
                    int mid = (l + h) / 2;
                    if (target >= PEOPLE[mid])
                        l = mid + 1;
                    else
                        h = mid;
                }

                l -= 1;
                if (l > n)
                    n = l;
            }
            else
                remain += SHIP[j];
        }

        DP[i] = n;
        if (n == N) res = max(res, remain);
    }

    printf("%d", res);
    return 0;
}