#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int dp[103][103];
bool check[103] = {false,};

int main()
{
	int n, m;
	queue<int> que;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i)
	{
		int temp1, temp2;

		scanf("%d %d", &temp1, &temp2);
	
		dp[temp1][temp2] = 1;
		dp[temp2][temp1] = 1;
	}

	int cnt = 0;

	que.push(1);
	check[1] = true;

	while (!que.empty())
	{
		int x = que.front();
		que.pop();

		for (int i = 1; i <= n; ++i)
		{
			if (dp[x][i] == 1 && !check[i])
			{
				que.push(i);
				check[i] = true;
			
				cnt++;
			}
		}
	}

	printf("%d", cnt);
	return 0;
}