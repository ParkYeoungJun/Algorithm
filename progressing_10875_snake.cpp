/*
	시작, 끝 점 저장
	vector< pair< pair<시작점> , pair<끝점> > >

	시간초과
*/

#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int dx[5] = {1, 0, -1, 0};
int dy[5] = {0, 1, 0, -1};

int main()
{
	int l, n;
	int result = 0;
	int direct = 0;
	bool finish = false;
	pair<int, int> current;
	pair<int, int> start;

	vector<pair< pair<int, int>, pair<int, int> > > vec;
	pair< pair<int, int>, pair<int, int> > insert_pair;

	scanf("%d", &l);

	current = make_pair(0, 0);
	start = make_pair(0, 0);

	scanf("%d", &n);

	for (int i = 0 ; i < n; ++i)
	{
		int temp_num;
		char temp_al;

		scanf("%d %c", &temp_num, &temp_al);

		for (int j = 0; j < temp_num; ++j)
		{
			result++;

			current = make_pair(current.first + dx[direct], current.second + dy[direct]);

			if (current.first > l || current.first < (-1)*l || current.second > l || current.second < (-1)*l)
			{
				printf("%d", result);

				finish = true;

				return 0;
			}
			else
			{
				for (vector<pair< pair<int, int>, pair<int, int> > >::iterator iter = vec.begin(); iter != vec.end(); ++iter)
				{
					if ((current.first >= (*iter).first.first && current.first <= (*iter).second.first)
						|| (current.first <= (*iter).first.first && current.first >= (*iter).second.first))
					{
						if(current.second == (*iter).first.second && current.second == (*iter).second.second)
						{
							printf("%d", result);

							return 0;
						}
					}
					else if ((current.second >= (*iter).first.second && current.second <= (*iter).second.second)
						|| (current.second <= (*iter).first.second && current.second >= (*iter).second.second))
					{
						if (current.first == (*iter).first.first && current.first == (*iter).second.first)
						{
							printf("%d", result);

							return 0;
						}
					}
				}
			}
		}

		if (temp_al == 'L')
		{
			if (++direct > 3)
				direct = 0;

			insert_pair = make_pair(make_pair(start.first, start.second), make_pair(current.first, current.second));

			vec.push_back(insert_pair);
		}
		else
		{
			if (--direct < 0)
				direct = 3;

			insert_pair = make_pair(make_pair(start.first, start.second), make_pair(current.first, current.second));

			vec.push_back(insert_pair);
		}
	}

	if (!finish)
	{
		while (true)
		{
			++result;

			current = make_pair(current.first + dx[direct], current.second + dy[direct]);
			
			if (current.first > l || current.first < (-1)*l || current.second > l || current.second < (-1)*l)
			{
				printf("%d", result);

				finish = true;

				return 0;
			}
			else
			{
				for (vector<pair< pair<int, int>, pair<int, int> > >::iterator iter = vec.begin(); iter != vec.end(); ++iter)
				{
					if ((current.first >= (*iter).first.first && current.first <= (*iter).second.first)
						|| (current.first <= (*iter).first.first && current.first >= (*iter).second.first))
					{
						if (current.second == (*iter).first.second && current.second == (*iter).second.second)
						{
							printf("%d", result);

							return 0;
						}
					}
					else if ((current.second >= (*iter).first.second && current.second <= (*iter).second.second)
						|| (current.second <= (*iter).first.second && current.second >= (*iter).second.second))
					{
						if (current.first == (*iter).first.first && current.first == (*iter).second.first)
						{
							printf("%d", result);

							return 0;
						}
					}
				}
			}
		}
	}

	return 0;
}