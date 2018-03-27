#include <iostream>
#include <cstdio>

using namespace std;

bool arr[1005];

int main()
{
    int n, k, cnt = 0;

    scanf("%d %d", &n, &k);

    for (int i = 2; i <= n; ++i)
    {
        if (!arr[i])
        {
            cnt++;
            if (cnt == k)
            {
                printf("%d", i);
                return 0;
            }

            for (int j = 2; i * j <= n; ++j)
            {
                if (!arr[i*j])
                {
                    arr[i * j] = true;
                    cnt++;

                    if (cnt == k)
                    {
                        printf("%d", i * j);
                        return 0;
                    }
                }
            }
        }
    }
}