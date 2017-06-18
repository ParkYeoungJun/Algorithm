#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<list>

using namespace std;

struct cmp
{
	bool operator ()(const pair<int, int> &a, const pair<int, int>&b)
	{
		return false;
	}
};

// apple = 1, snake = -1, initial = 0
int board[102][102];
std::set<pair<int, int> > direct;
std::vector<pair<int, int> > snake;

// 오른쪽 부터 시계방향. %4
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
	int size, apple_num, direct_num, cur_direct = 0, second = 0, snake_size = 1;

	scanf("%d %d", &size, &apple_num);

	for (int i = 0; i < apple_num; ++i)
	{
		int temp1, temp2;

		scanf("%d %d", &temp1, &temp2);

		board[temp1][temp2] = 1;
	}

	scanf("%d", &direct_num);

	for (int i = 0; i < direct_num; ++i)
	{
		int temp1, temp2;
		char tempc;

		scanf("%d %c", &temp1, &tempc);

		if (tempc == 'D')
			temp2 = 1;
		else if (tempc == 'L')
			temp2 = -1;

		direct.insert(make_pair(temp1, temp2));
	}

	snake.push_back(make_pair(1, 1));
	
	int to_x, to_y;

	while (true)
	{
		if ((*direct.begin()).first == second)
		{
			cur_direct = (cur_direct + (*direct.begin()).second) % 4;
		
			if (cur_direct < 0)
				cur_direct = 3;

			direct.erase(direct.begin());
		}

		to_x = (snake.back()).first + dx[cur_direct];
		to_y = (snake.back()).second + dy[cur_direct];

		if (to_x < 1 || to_x > size || to_y < 1 || to_y > size)	 // 판을 벗어날 경우
		{
			printf("%d", second+1);

			return 0;
		}
		else
		{
			bool find = false;

			for (int i = 0; i < snake.size(); ++i)
			{
				if (snake[i].first == to_x && snake[i].second == to_y)
					find = true;
			}

			if (find)
			{
				printf("%d", second + 1);

				return 0;
			}

			if (snake_size == snake.size())
			{
				snake.erase(snake.begin());
			}

			snake.push_back(make_pair(to_x, to_y));

			if (board[to_x][to_y] == 1)
			{
				snake_size++;

				board[to_x][to_y] = 0;
			}
		}

		second++;
	}


	return 0;
}