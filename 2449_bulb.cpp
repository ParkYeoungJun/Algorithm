#include<iostream>
#include<cstdio>

using namespace std;

int n, col_size;
int arr[205];
int dp[205][205];

int solve(int left, int right)
{
    if(left == right)
        return 0;
    
    if(arr[left] == arr[left + 1])
        return solve(left+1, right);

    if(arr[right] == arr[right - 1])
        return solve(left, right-1);

    if(dp[left][right] != 0)
        return dp[left][right];

    dp[left][right] += solve(left+1, right) + 1;

    for(int i = left + 1 ; i <= right ; ++i)
    {
        if(arr[i] == arr[left])
        {
            dp[left][right] = min(solve(left + 1, i - 1) + solve(i, right) + 1, dp[left][right]);
        }
    }

    return dp[left][right];
}

int main()
{
    scanf("%d %d", &n, &col_size);

    for(int i = 1 ; i <= n ; ++i)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", solve(1,n));

    return 0;
}