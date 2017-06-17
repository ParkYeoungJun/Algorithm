#include<cstdio>
#include<iostream>
#include<set>

using namespace std;

struct cmp
{
	bool operator ()(const pair<int, int> &a, const pair<int, int> &b)
	{
		return a.second < b.second;
	}
};

int main()
{
	int a, b, c, size, cost = 0;
	std::set<pair<int, int>, cmp> arr;
	std::set<pair<int, int> >::iterator iter;

	scanf("%d %d %d", &a, &b, &c);

	for (int i = 0; i < 3; ++i)
	{
		int temp1, temp2;

		scanf("%d %d", &temp1, &temp2);

		arr.insert(make_pair(temp1, temp2));
	}

	iter = arr.end();
	size = (*(--iter)).second;

	for (int i = 1; i <= size; ++i)
	{
		int num = 0;

		iter = arr.begin();
		for (; iter != arr.end(); iter++)
		{
			if ((*iter).first <= i && (*iter).second > i)
				++num;
		}

		if (num == 1)
			cost += a;
		else if (num == 2)
			cost += (b*2);
		else if (num == 3)
			cost += (c*3);
	}

	printf("%d", cost);

	return 0;
}