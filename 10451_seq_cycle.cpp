#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	int t, n;
	vector<int> arr[1005];
	queue<int> que;
	int cnt = 0;

	scanf("%d", &t);

	while (t--)
	{
		scanf("%d", &n);

		bool visit[1005] = { false, };

		for (int i = 1; i <= n; ++i)
		{
			int temp;

			scanf("%d", &temp);

			arr[i].push_back(temp);
		}

		for (int i = 1; i <= n; ++i)
		{
			if (!visit[i])
			{
				que.push(i);

				while (!que.empty())
				{
					int temp = que.front();
					que.pop();

					visit[temp] = true;

					for (int i = 0; i < arr[temp].size(); ++i)
					{
						if (!visit[arr[temp][i]])
							que.push(arr[temp][i]);
					}

				}

				cnt++;
			}
		}

		printf("%d\n", cnt);

		for (int i = 1; i <= n; ++i)
			arr[i].clear();

		cnt = 0;
	}
}