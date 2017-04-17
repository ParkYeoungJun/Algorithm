#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

int main()
{
	int input;
	int dp[1000002]= {0,};

	dp[1] = 0;
	dp[2] = 1;
	
	scanf_s("%d", &input);

	for (int i = 3; i <= input; ++i)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);

		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	printf("%d", dp[input]);

	return 0;
}