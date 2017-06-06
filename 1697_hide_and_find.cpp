#include<cstdio>
#include<queue>
#include<iostream>

using namespace std;

int visit[100002];

void seek(int n, int m)
{
	queue<int> queue;
	queue.push(n);
	visit[n] = 1;
	
	while (!queue.empty())
	{
		int temp = queue.front();
		queue.pop();

		if (temp == m)
		{
			printf("%d", visit[temp]-1);
		}
		else
		{
			if (temp-1 >= 0 && visit[temp-1] == 0)
			{
				visit[temp - 1] = visit[temp] + 1;
				queue.push(temp - 1);
			}
			if (temp+1 <= 100000 && visit[temp+1] == 0)
			{
				visit[temp + 1] = visit[temp] + 1;
				queue.push(temp + 1);
			}
			if (temp*2 <= 100000 && visit[temp*2] == 0)
			{
				visit[temp * 2] = visit[temp] + 1;
				queue.push(temp * 2);
			}
		}

	}
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	seek(n, m);

	return 0;
}