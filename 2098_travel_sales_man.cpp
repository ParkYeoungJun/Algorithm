#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define INF 1 << 29

int arr[20][20];
int dp[1 << 20][20];
int n;

int TSP(int visit, int cur)
{
    if(visit == (1 << n) - 1)
        return arr[cur][0] ? arr[cur][0] : INF;

    if(!dp[visit][cur])
    {
        dp[visit][cur] = INF;
        for(int i = 0 ; i < n ; ++i)
        {
            if(arr[cur][i] && !(visit & (1 << i)))
            {
                dp[visit][cur] = min(dp[visit][cur], TSP(visit | (1 << i), i) + arr[cur][i]);
            }
        }
    }

    return dp[visit][cur];
}

int main()
{
    scanf("%d", &n);

    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d", TSP(1, 0));

    return 0;
}