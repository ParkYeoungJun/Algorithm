#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>

using namespace std;

int dp[1000002];
bool broken[12];

int promise(int num)
{
	int len = 0;

	if (num == 0)
	{
		if (broken[num] == true)
			return 0;
		else
			return 1;
	}
	else
	{
		while (num > 0)
		{
			if (broken[num % 10] == true)
				return 0;
			else
			{
				num /= 10;

				len++;
			}
		}
	}

	return len;
}

int main()
{
	int to, n;
	scanf("%d", &to);
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		int temp;

		scanf("%d", &temp);

		broken[temp] = true;
	}

	dp[100] = 0;

	if (to == 100)
	{
		printf("0");
		return 0;
	}

	for (int i = 101; i < 1000000; ++i)
	{
		dp[i] = i - 100;
	}

	for (int i = 0; i <= 99; ++i)
	{
		dp[i] = abs(i - 100);
	}

	// 현재에서 to로 가는길
	for (int i = 0; i < 1000000; ++i)
	{
		int len = promise(i);

		if (len > 0)
		{
			int diff = abs(to - i);
			
			dp[to] = min(len + diff, dp[to]);
		}
	}

	printf("%d", dp[to]);

	return 0;
}