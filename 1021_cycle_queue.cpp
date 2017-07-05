#include<iostream>
#include<cstdio>
#include<deque>

using namespace std;

#define SIZE 52

deque<int> arr, a, b;
int num[SIZE];

int main()
{
	int n, m, a_cnt, b_cnt, cnt = 0;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
		arr.push_back(i);

	for (int i = 1; i <= m; ++i)
		scanf("%d", &num[i]);

	for (int i = 1; i <= m; ++i)
	{
		a = arr;
		b = arr;

		a_cnt = 0;
		b_cnt = 0;

		while (a.front() != num[i])
		{
			++a_cnt;
			a.push_back(a.front());
			a.pop_front();
		}

		while (b.front() != num[i])
		{
			++b_cnt;
			b.push_front(b.back());
			b.pop_back();
		}

		if (a_cnt < b_cnt)
		{
			arr = a;
			cnt += a_cnt;
		}
		else
		{
			arr = b;
			cnt += b_cnt;
		}

		arr.pop_front();

		a.clear();
		b.clear();
	}

	printf("%d", cnt);

	return 0;
}