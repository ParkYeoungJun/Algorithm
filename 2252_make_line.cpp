#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

vector<int> indegree;
vector<vector<int> > arr;
int n, m;

void bfs()
{
	queue<int> que;

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

		for (int i = 0; i < arr[temp].size(); ++i)
		{
			int to = arr[temp][i];

			indegree[to]--;

			if (indegree[to] == 0)
				que.push(to);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	indegree.resize(n + 5);
	arr.resize(n + 5);

	for (int i = 0; i < m; ++i)
	{
		int temp1, temp2;

		scanf("%d %d", &temp1, &temp2);

		indegree[temp2]++;
		arr[temp1].push_back(temp2);
	}

	bfs();
}