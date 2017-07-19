#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	int n, m;
	vector<int> arr[10005];
	queue<int> que;
	int result[10005] = { 0, };
	int size = 0;
	int maxi = -1;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		arr[temp2].push_back(temp1);
	}

	for (int i = 1; i <= n; ++i)
	{
		int cnt = 0;
		bool visit[10001] = { false, };

		que.push(i);
		visit[i] = 1;
		cnt++;

		while (!que.empty())
		{
			int temp = que.front();
			que.pop();

			for (int j = 0; j < arr[temp].size(); ++j)
			{
				int cur = arr[temp][j];

				if (!visit[cur])
				{
					visit[cur] = true;
					que.push(cur);
					cnt++;
				}
			}
		}

		if (maxi < cnt)
		{
			maxi = cnt;
			size = 0;
			result[size++] = i;
		}
		else if (maxi == cnt)
			result[size++] = i;

	}

	for (int i = 0; i < size; ++i)
		printf("%d ", result[i]);

	return 0;
}