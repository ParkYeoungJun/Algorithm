#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int dp[1003][1003];
int ans[1003][1003];
int dx[5] = {1,0,-1,0};
int dy[5] = {0,1,0,-1};
queue<pair<int, int> > que;

int main()
{
	int n, m;
	bool no_flag = false, all_flag = false;

	scanf("%d %d", &m, &n);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d", &dp[i][j]);

			if (dp[i][j] == 0)
				all_flag = true;

			if (dp[i][j] == 0 || dp[i][j] == 1)
				no_flag = true;

			if (dp[i][j] == 1)
			{
				que.push(make_pair(i, j));
			}
		}
	}

	if (!no_flag)
	{
		printf("0");
		return 0;
	}
	else if (!all_flag)
	{
		printf("0");
		return 0;
	}
	else 
	{
		while (!que.empty())
		{
			int x = que.front().first, y = que.front().second;
		
			que.pop();

			for (int i = 0; i < 4; ++i)
			{
				if (dp[x + dx[i]][y + dy[i]] != -1)
				{
					if (dp[x + dx[i]][y + dy[i]] != 1 && x + dx[i] > 0 &&
						x + dx[i] <= n && y + dy[i] > 0 && y + dy[i] <= m)
					{
						dp[x + dx[i]][y + dy[i]] = 1;
						ans[x + dx[i]][y + dy[i]] = ans[x][y] + 1;

						que.push(make_pair(x + dx[i], y + dy[i]));
					}
				}
			}
		}

		int maxi = -1;

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				maxi = max(ans[i][j], maxi);

				if (dp[i][j] == 0)
				{
					printf("-1");
					return 0;
				}
			}
		}
	
		printf("%d", maxi);
	}
	
	return 0;
}