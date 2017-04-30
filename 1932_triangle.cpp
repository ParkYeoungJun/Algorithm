#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int dp[502][502];
int array[502][502];

int main(void)
{
    int size;

    scanf("%d" , &size);

    for(int i = 1 ; i <= size ; ++i)
    {
        for(int j = 1 ; j <= i ; ++j)
        {
            scanf("%d", &array[i][j]);
        }
    }

    dp[1][1] = array[1][1];

    int maxi = dp[1][1];

    for(int i = 2 ; i <= size ; ++i)
    {
        for(int j = 1 ; j <= i ; ++j)
        {
            if(j == 1)
                dp[i][j] = dp[i-1][j] + array[i][j];
            else if(j > 1 && j < i)
                dp[i][j] = max(dp[i-1][j-1] , dp[i-1][j]) + array[i][j];
            else
                dp[i][j] = dp[i-1][j-1] + array[i][j];

            if(dp[i][j] > maxi)
                maxi = dp[i][j];

        }
    }

    printf("%d", maxi);

    return 0;
}
