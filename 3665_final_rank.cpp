#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int t, n, m, x, y;

int main() {
	
	scanf("%d", &t);
	
	while (t--) {
		
		int flag = 0;
		int g[505][505] = { 0, };
		int in[505] = { 0, };
		int old[505] = { 0, };
		int re[505] = { 0, };
		
		scanf("%d", &n);
		
		for (int i = 0; i < n; i++)
			scanf("%d", &old[i]);
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {

				g[old[j]][old[i]] = 1;
				in[old[i]]++;

			}
		}

		scanf("%d", &m);

		while (m--) {

			scanf("%d%d", &x, &y);

			if (a[x][y]) {
				in[y]--;
				in[x]++;
			}
			else {
				in[y]++;
				in[x]--;
			}

			swap(g[x][y], g[y][x]);
		}

		queue<int> que;

		for (int i = 1; i <= n; i++) {

			if (!in[i])
				que.push(i);

		}

		for (int i = 0; i < n; i++) {

			if (que.empty()) {
				flag = 1;
				break;
			}
			else if (que.size() > 1) {
				flag = 2;
				break;
			}

			int here = que.front();

			re[i] = here;

			que.pop();

			for (int j = 1; j <= n; j++) {

				if (g[here][j]) {

					in[j]--;

					if (!in[j])
						que.push(j);
				}
			}
		}

		if (flag == 1)
		{
			printf("IMPOSSIBLE\n");
		}
		else if (flag == 2)
		{
			printf("?\n");
		}
		else 
		{
			for (int i = 0; i < n; i++)
				printf("%d ", re[i]);

			printf("\n");
		}
	}


	return 0;
}