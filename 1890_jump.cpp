#include<iostream>
#include<cstdio>

using namespace std;

long long int dp[150][150];
int input[150][150];

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &input[i][j]);

	dp[1][1] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == n && j == n)
			{
				printf("%lld", dp[n][n]);
				return 0;
			}

			dp[i + input[i][j]][j] += dp[i][j];
			dp[i][j + input[i][j]] += dp[i][j];
		}
	}
}