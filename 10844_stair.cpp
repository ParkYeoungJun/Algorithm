#include<iostream>
#include<stdio.h>

using namespace std;

#define mod 1000000

int main()
{
	int n;
	int dp[102][12] = {0,};
	int result = 0;

	scanf("%d", &n);

	dp[1][0] = 0;

	for(int i = 1 ; i <= 9 ; ++i)
		dp[1][i] = 1;

	for(int i = 2 ; i <= n ; ++i)
	{
		for(int j = 0 ; j <= 9 ; ++j)
		{
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
		}
	}

	for(int i = 0 ; i <= 9 ; ++i)
		result += dp[n][i];

	printf("%d", result % mod);
}
