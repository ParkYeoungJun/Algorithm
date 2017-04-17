// 재귀로 DFS 후 Memoization

#include<iostream>
#include<stdio.h>

using namespace std;

int x,y;
int input[502][502];
int dp[502][502];

int dx[5] = {0, 1, 0, -1};
int dy[5] = {1, 0, -1, 0};

void dfs(int dfs_x, int dfs_y)
{
//parkyeoungjun mong choong e


	
}

int main()
{
	scanf("%d %d", &x, &y);

	for(int i = 1 ; i <= x ; ++i)
		for(int j = 1 ; j <= y ; ++j)
			scanf("%d", &input[i][j]);

	dfs(1, 1);


	return 0;
}
