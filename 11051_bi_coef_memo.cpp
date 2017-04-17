#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

#define mod 10007

int dp[1002][1002];

int main()
{
	int n=0, k=0;

	scanf("%d %d", &n, &k);

	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for(int i = 2 ; i <= n ; ++i)
	{
		for(int j = 0 ; j <= k ; ++j)
		{
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			dp[i][j] %= mod;
		}
	}

	printf("%d", dp[n][k]);


	return 0;

}

