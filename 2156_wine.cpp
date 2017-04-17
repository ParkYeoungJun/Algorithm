#include<iostream>
#include<stdio.h>

using namespace std;

int max(int a, int b, int c)
{
	int temp_max = 0;

	if(a < b)
		temp_max = b;
	else
		temp_max = a;

	if(temp_max < c)
		temp_max = c;

	return temp_max;
}

int main()
{
	int n;
	int input[10002] = {0,};
	int dp[10002] = {0,};

	scanf("%d", &n);

	for(int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", &input[i]);
	}

	dp[1] = input[1];
	dp[2] = input[1] + input[2];
	dp[3] = max(dp[2], dp[1] + input[3], input[2] + input[3]);

	for(int i = 4 ; i <= n ; ++i)
	{
		dp[i] = max(dp[i-3] + input[i-1] + input[i], dp[i-2] + input[i], dp[i-1]);
	}

	printf("%d", dp[n]);
	
	return 0;
}
