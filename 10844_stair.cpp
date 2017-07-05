#include<iostream>
#include<stdio.h>

using namespace std;

#define mod 1000000000

int main()
{
	int n;
	long long dp[102][12] = {0,};
	long long result = 0;

	scanf("%d", &n);

	dp[1][0] = 0;

	for(int i = 1 ; i <= 9 ; ++i)
		dp[1][i] = 1;

	for(int i = 2 ; i <= n ; ++i)
	{
		for(int j = 0 ; j <= 9 ; ++j)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1] % mod;
			else if (j == 9)
				dp[i][j] = dp[i - 1][8] % mod;
			else
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
		}
	}

	for(int i = 0 ; i <= 9 ; ++i)
		result += dp[n][i] % mod;

	printf("%d", result % mod);

	return 0;
}
