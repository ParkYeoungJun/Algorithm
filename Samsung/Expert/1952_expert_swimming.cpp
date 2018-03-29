#include<iostream>
#include<cstdio>

using namespace std;

int cost[5];
int plan[13];
int dp[15];

int main()
{
    int t, res, cnt = 1;

    scanf("%d", &t);

    while(t--)
    {
        for(int i = 1 ; i <= 4 ; ++i)
            scanf("%d", &cost[i]);
        for(int i = 1 ; i <= 12 ; ++i)
            scanf("%d", &plan[i]);

        dp[1] = min(cost[1]*plan[1], cost[2]);
        dp[2] = min(dp[1] + cost[1]*plan[2], dp[1] + cost[2]); 
        for(int i = 3 ; i <= 12 ; ++i)
        {
            int tmpA = dp[i-1] + cost[1]*plan[i];
            int tmpB = dp[i-1] + cost[2];
            int tmpC = dp[i-3] + cost[3];
            tmpA = min(tmpA, tmpB);
            dp[i] = min(tmpA, tmpC);
        }

        res = min(dp[12], cost[4]);

        printf("#%d %d\n", cnt++, res);
    }
}