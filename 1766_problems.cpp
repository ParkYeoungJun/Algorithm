#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<int> arr[32005];
vector<int> re[32006];
int indegree[32005];

void bfs()
{
	queue<int> que;
	int cnt = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (indegree[i] == 0)
			que.push(i);
	}

	while (!que.empty())
	{
		int temp = que.front();

		que.pop();

		printf("%d ", temp);
	
		re[cnt].push_back(temp);

		for (int i = 0; i < arr[temp].size(); ++i)
		{
			int to = arr[temp][i];

			indegree[to]--;

			if (indegree[to] == 0)
			{
				re[cnt].push_back(to);

				que.push(to);
			}
		}

		cnt++;
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i)
	{
		int temp1, temp2;

		scanf("%d %d", &temp1, &temp2);

		indegree[temp2]++;
		arr[temp1].push_back(temp2);
	}
	
	bfs();

	cout << endl;

	for (int i = 0; i <= cnt; ++i);

	return 0;
}