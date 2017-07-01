// 재귀로 DFS 후 Memoization

#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

int x,y;
int input[502][502];
int dp[502][502];

int dx[5] = {0, 1, 0, -1};
int dy[5] = {1, 0, -1, 0};

int dfs(int dfs_x, int dfs_y)
{
	if (dfs_x == x && dfs_y == y)
		return 1;
	else if (dp[dfs_x][dfs_y] >= 0)
		return dp[dfs_x][dfs_y];
	else if (dp[dfs_x][dfs_y] == -1)
		dp[dfs_x][dfs_y] = 0;

	
	for (int i = 0; i < 4; ++i)
	{
		if (input[dfs_x + dx[i]][dfs_y + dy[i]] < input[dfs_x][dfs_y]
			&& dfs_x + dx[i] > 0 && dfs_x + dx[i] <= x && dfs_y + dy[i] > 0 && dfs_y + dy[i] <= y)
		{
			dp[dfs_x][dfs_y] += dfs(dfs_x + dx[i], dfs_y + dy[i]);
		}
	}

	return dp[dfs_x][dfs_y];
	
}

int main()
{
	scanf("%d %d", &x, &y);

	for(int i = 1 ; i <= x ; ++i)
		for(int j = 1 ; j <= y ; ++j)
			scanf("%d", &input[i][j]);

	memset(dp, -1, sizeof(dp));
	dp[x][y] = 1;

	dfs(1, 1);

	printf("%d", dp[1][1]);

	return 0;
}

/*
3 3
5 4 3
4 3 2
3 2 9
*/
