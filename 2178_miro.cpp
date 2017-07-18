#include<iostream>
#include<cstdio>
#include<queue>
#include<string>

using namespace std;

int dp[103][103];
bool check[103][103] = {false,};

int dx[5] = { 1,0,-1,0 };
int dy[5] = { 0,1,0,-1 };

int n, m, result = 0;

int main()
{
	queue<pair<int, int> > que;
	string str;
	
	scanf("%d %d", &n, &m);

	cin.ignore();

	for (int i = 1; i <= n; ++i)
	{
		getline(cin, str);

		for (int j = 0; j < m; ++j)
		{
			dp[i][j + 1] = str.at(j) - '0';
		}
	}

	que.push(make_pair(1, 1));

	while (!que.empty())
	{
		int x = que.front().first, y = que.front().second;
		
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int to_x = x + dx[i], to_y = y + dy[i];

			if (to_x > 0 && to_x <= n && to_y > 0 && to_y <= m)
			{
				if (!check[to_x][to_y] && dp[to_x][to_y] != 0)
				{
					check[to_x][to_y] = true;
					dp[to_x][to_y] = dp[x][y] + 1;

					que.push(make_pair(to_x, to_y));
				}
			}
		}
	}

	printf("%d", dp[n][m]);
}