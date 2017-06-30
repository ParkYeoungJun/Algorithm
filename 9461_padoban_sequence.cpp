#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int size, temp, maxi = -1;
	long long dp[102] = {0,};
	vector<int> input;

	scanf("%d", &size);

	for (int i = 0; i < size; ++i)
	{
		scanf("%d", &temp);

		maxi = max(temp, maxi);

		input.push_back(temp);
	}

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;

	for (int i = 7; i <= maxi; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	for (int i = 0; i < input.size(); ++i)
	{
		printf("%lld\n", dp[input.at(i)]);
	}

	return 0;
}