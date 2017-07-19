
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int dp[30][30];
int dx[5] = { 1,0,-1,0 };
int dy[5] = { 0,1,0,-1 };
int n;
int result, cnt;

int bfs(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int to_x = x + dx[i], to_y = y + dy[i];

		if (to_x > 0 && to_x <= n && to_y > 0 && to_y <= n && dp[to_x][to_y] == 0)
		{
			dp[to_x][to_y] = result;
			cnt = bfs(to_x, to_y);
			cnt++;
		}		
	}

	return cnt;
}

int main()
{
	string str;
	vector<int> arr;

	scanf("%d", &n);

	cin.ignore();

	for (int i = 1; i <= n; ++i)
	{
		getline(cin, str);

		for (int j = 0; j < n; ++j)
		{
			if (str.at(j) - '0' == 1)
				dp[i][j + 1] = 0;
			else
				dp[i][j + 1] = -1;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (dp[i][j] == 0)
			{
				++result;
				arr.push_back(bfs(i, j));
				cnt = 0;
			}
		}
	}

	sort(arr.begin(), arr.end(), less<int>());

	printf("%d\n", result);

	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr.at(i) == 0)
			printf("1\n");
		else
			printf("%d\n", arr.at(i));
	}

	return 0;
}