#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int dp[103][103][103];
int ans[103][103][103];
int dh[8] = { 0, 0, 0, 0, 1, -1 };
int dx[8] = { 1, 0, -1, 0, 0, 0 };
int dy[8] = { 0, 1, 0, -1, 0, 0 };
queue<pair<int, pair<int,int > > > que;

int main()
{
	int n, m, z;
	bool no_flag = false, all_flag = false;

	scanf("%d %d %d", &m, &n, &z);

	for (int k = 1; k <= z; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				scanf("%d", &dp[k][i][j]);

				if (dp[k][i][j] == 0)
					all_flag = true;

				if (dp[k][i][j] == 0 || dp[k][i][j] == 1)
					no_flag = true;

				if (dp[k][i][j] == 1)
				{
					que.push(make_pair(k, make_pair(i, j)));
				}
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
			int h = que.front().first, x = que.front().second.first, y = que.front().second.second;
		
			que.pop();

			for (int i = 0; i < 6; ++i)
			{
				if (dp[h + dh[i]][x + dx[i]][y + dy[i]] != -1)
				{
					if (dp[h + dh[i]][x + dx[i]][y + dy[i]] != 1 && x + dx[i] > 0 &&
						x + dx[i] <= n && y + dy[i] > 0 && y + dy[i] <= m &&
						h + dh[i] > 0 && h + dh[i] <= z)
					{
						dp[h + dh[i]][x + dx[i]][y + dy[i]] = 1;
						ans[h + dh[i]][x + dx[i]][y + dy[i]] = ans[h][x][y] + 1;

						que.push(make_pair(h + dh[i], make_pair(x + dx[i], y + dy[i])));
					}
				}
			}
		}

		int maxi = -1;

		for (int k = 1; k <= z; ++k)
		{
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= m; ++j)
				{
					maxi = max(ans[k][i][j], maxi);

					if (dp[k][i][j] == 0)
					{
						printf("-1");
						return 0;
					}
				}
			}
		}
		
		printf("%d", maxi);
	}
	
	return 0;
}