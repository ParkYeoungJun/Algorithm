#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int dp[1002][4];
int pay[1002][4];


int main(void)
{
    int size;

    scanf("%d", &size);

    for(int i = 1 ; i <= size ; ++i)
    {
        scanf("%d %d %d", &pay[i][1], &pay[i][2], &pay[i][3]);
    }

    dp[1][1] = pay[1][1];
    dp[1][2] = pay[1][2];
    dp[1][3] = pay[1][3];

    for(int i = 2 ; i <= size ; ++i)
    {
        // R
        if(dp[i-1][2] > dp[i-1][3]) 
            dp[i][1] = dp[i-1][3] + pay[i][1];
        else
            dp[i][1] = dp[i-1][2] + pay[i][1];

        // G
        if(dp[i-1][1] > dp[i-1][3]) 
            dp[i][2] = dp[i-1][3] + pay[i][2];
        else
            dp[i][2] = dp[i-1][1] + pay[i][2];

        // B
        if(dp[i-1][1] > dp[i-1][2]) 
            dp[i][3] = dp[i-1][2] + pay[i][3];
        else
            dp[i][3] = dp[i-1][1] + pay[i][3];
    }

    int result;

    if(dp[size][1] > dp[size][2])
        result = dp[size][2];
    else
        result = dp[size][1];

    if(result > dp[size][3])
        printf("%d", dp[size][3]);
    else
        printf("%d", result);

}
