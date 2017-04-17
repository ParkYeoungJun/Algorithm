#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int n, k;
	int dp[10002] = {0,};
	int input[102] = {0,};


	scanf("%d %d", &n, &k);

	for(int i = 1 ; i <= n ; ++i)
		scanf("%d", &input[i]);


	dp[0] = 1;

	for(int i = 0 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= k ; ++j)
		{
			if(j >= input[i])
				dp[j] += dp[j - input[i]];
		}
	}

	printf("%d", dp[k]);

	return 0;
}
