#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

vector<int> arr[505];
int indegree[505];
int t[505];
int re[505];
int n;

void bfs()
{
	queue<int> que;

	for (int i = 1; i <= n; ++i)
	{
		if (indegree[i] == 0)
		{
			re[i] = t[i];
			que.push(i);
		}
	}

	while (!que.empty())
	{
		int temp = que.front();
		que.pop();

		for (int i = 0; i < arr[temp].size(); ++i)
		{
			int to = arr[temp][i];

			indegree[to]--;

			re[to] = max(re[to], re[temp] + t[to]);

			if (indegree[to] == 0)
			{
				que.push(to);
			}
		}
	}
}

int main()
{
	int temp;

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &temp);

		t[i] = temp;

		while (true)
		{
			scanf("%d", &temp);

			if (temp != -1)
			{
				arr[temp].push_back(i);
				indegree[i]++;
			}
			else
				break;
		}
	}

	bfs();

	for (int i = 1; i <= n; ++i)
		printf("%d\n", re[i]);

	return 0;
}