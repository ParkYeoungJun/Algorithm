/*
	시작, 끝 점 저장
	vector< pair< pair<시작점> , pair<끝점> > >

	시간초과
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<limits.h>

using namespace std;

int dx[5] = {1, 0, -1, 0};
int dy[5] = {0, 1, 0, -1};

int main()
{
	int l, n;
	int result = 0;
	int direct = 0;
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

		current = make_pair(current.first + (dx[direct] * temp_num), current.second + (dy[direct] * temp_num));

		cout << "start first : " << start.first << " start second : " << start.second << endl;
		cout << "current first : " << current.first << " current second : " << current.second << endl;

		cout << "result : " << result << endl;

		for (vector<pair< pair<int, int>, pair<int, int> > >::iterator iter = vec.begin(); iter != vec.end(); ++iter)
		{
			cout << "vec fir fir : " << (*iter).first.first << " vec fir sec : " << (*iter).first.second << endl;
			cout << "vec sec fir : " << (*iter).second.first << " vec sec sec : " << (*iter).second.second << endl;


			if ((*iter).second.first != start.first && (*iter).second.second != start.second)
			{

				int current_max, current_min, line_max, line_min;
				int cy_max, cy_min, vy_max, vy_min;

				current_max = max(current.first, start.first);
				current_min = min(current.first, start.first);
				line_max = max((*iter).first.first, (*iter).second.first);
				line_min = min((*iter).first.first, (*iter).second.first);

				cy_max = max(current.second, start.second);
				cy_min = min(current.second, start.second);
				vy_max = max((*iter).first.second, (*iter).second.second);
				vy_min = min((*iter).first.second, (*iter).second.second);

				if (current_min <= line_min && current_max >= line_max)
				{
					if (vy_min <= cy_min && vy_max >= cy_max)
					{
						result += abs(start.first - (*iter).first.first);

						printf("%d", result);

						return 0;
					}
				}

				if (line_min <= current_min && line_max >= current_max)
				{
					if (cy_min <= vy_min && cy_max >= vy_max)
					{
						result += abs(start.second - (*iter).first.second);

						printf("%d", result);

						return 0;
					}
				}
			}
		}

		result += temp_num;


		if (current.first > l)
		{
			result += temp_num - (current.first - l) + 1;

			printf("%d", result);

			return 0;
		}
		else if (current.first < (-1) * l)
		{
			result += temp_num - ((-1) * current.first - (-1) * l) + 1;

			printf("%d", result);

			return 0;
		}
		else if (current.second > l)
		{
			result += temp_num - (current.second - l) + 1;
			
			printf("%d", result);

			return 0;
		}
		else if (current.second < (-1)*l)
		{
			result += temp_num - ((-1) * current.second - (-1) * l) + 1;

			printf("%d", result);

			return 0;
		}


		if (temp_al == 'L')
		{
			cout << "asdf" << endl;

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

		start = current;
	}

	int mini = INT_MAX;
	int temp_result = result;


		if (direct == 0)
			current = make_pair(l, current.second);
		else if (direct == 1)
			current = make_pair(current.first, l);
		else if (direct == 2)
			current = make_pair((-1)*l, current.second);
		else if (direct == 3)
			current = make_pair(current.first, (-1)*l);

		for (vector<pair< pair<int, int>, pair<int, int> > >::iterator iter = vec.begin(); iter != vec.end(); ++iter)
		{
			if ((*iter).second.first != start.first && (*iter).second.second != start.second)
			{
				result = temp_result;

				cout << "finished" << endl;
				cout << "vec fir fir : " << (*iter).first.first << " vec fir sec : " << (*iter).first.second << endl;
				cout << "vec sec fir : " << (*iter).second.first << " vec sec sec : " << (*iter).second.second << endl;
				cout << "start first : " << start.first << " start second : " << start.second << endl;
				cout << "current first : " << current.first << " current second : " << current.second << endl;
				cout << "result : " << result << endl;

				int current_max, current_min, line_max, line_min;
				int cy_max, cy_min, vy_max, vy_min;

				current_max = max(current.first, start.first);
				current_min = min(current.first, start.first);
				line_max = max((*iter).first.first, (*iter).second.first);
				line_min = min((*iter).first.first, (*iter).second.first);

				cy_max = max(current.second, start.second);
				cy_min = min(current.second, start.second);
				vy_max = max((*iter).first.second, (*iter).second.second);
				vy_min = min((*iter).first.second, (*iter).second.second);

				if (current_min <= line_min && current_max >= line_max)
				{
					if (vy_min <= cy_min && vy_max >= cy_max)
					{
						result += abs(start.first - (*iter).first.first);

						mini = min(result, mini);

						//printf("%d", result);
					}
				}

				if (line_min <= current_min && line_max >= current_max)
				{
					if (cy_min <= vy_min && cy_max >= vy_max)
					{
						result += abs(start.second - (*iter).first.second);

						mini = min(result, mini);

						//printf("%d", result);
					}
				}
			}
		}

	if (mini == INT_MAX)
	{
		if (direct == 0 || direct == 2)
			result += abs(current.first - start.first) + 1;
		else if (direct == 1 || direct == 3)
			result += abs(current.second - start.second) + 1;
		
		printf("%d", result);
	}
	else
	{
		printf("%d", result);
	}
	

	return 0;
}