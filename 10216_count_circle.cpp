#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

#define makepair(a, b, c) make_pair(make_pair(a, b), c);

vector<int> adj[3005];
typedef pair<pair<int, int>, int> type_c;
type_c comp[3005];

bool comp_adj(type_c x, type_c y)
{
	int dis = (x.first.first - y.first.first)*(x.first.first - y.first.first) 
		+ (x.first.second - y.first.second)*(x.first.second - y.first.second);

	return dis <= (x.second + y.second) * (x.second + y.second);
}

int main()
{
	int t, n, x, y, r, cnt = 0;

	scanf("%d", &t);

	while (t--)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d %d", &x, &y, &r);

			comp[i] = makepair(x, y, r);

			adj[i].clear();
		}

		bool visited[3005] = { false, };

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (comp_adj(comp[i], comp[j]))
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		queue<int> que;

		for (int i = 0; i < n; ++i)
		{
			if (visited[i])
				continue;

			visited[i] = true;

			que.push(i);

			while (!que.empty())
			{
				int temp = que.front();
				que.pop();

				for (int j = 0; j < adj[temp].size(); ++j)
				{
					int to = adj[temp][j];
					if (!visited[to])
					{
						visited[to] = true;
						que.push(to);
					}
				}
			}

			cnt++;
		}

		printf("%d\n", cnt);

		cnt = 0;
	}

	return 0;
}