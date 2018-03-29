#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool broken[15];
int to;
int dp[1000005];

int promise(int n)
{
    int rtn = 0;

    if(n == 0)
    {
        if(broken[0])
            return 0;
        else
            return 1;
    }
    else
    {
        while(n > 0)
        {
            if(broken[n % 10])
                return 0;
            else
            {
                rtn++;
                n /= 10;
            }  
        }
    }

    return rtn;
}

int main()
{
    int to, n;

    scanf("%d", &to);
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        broken[tmp] = true;
    }

    if (to == 100)
    {
        printf("0");
        return 0;
    }
    else
    {

        for (int i = 0; i < 100; ++i)
            dp[i] = 100 - i;
        for (int i = 101; i <= 1000000; ++i)
            dp[i] = i - 100;

        for (int i = 0; i <= 1000000; ++i)
        {
            int len = promise(i);
            
            if(len > 0){
                int diff = abs(to - i);
                dp[to] = min(len + diff, dp[to]);            
            }
        }
    }

    printf("%d", dp[to]);
}