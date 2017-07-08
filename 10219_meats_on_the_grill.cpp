#include<iostream>
#include<cstdio>

using namespace std;

<<<<<<< HEAD
char arr[13][13];

// 뒤집기, 90도, 180도, 270도 함수 구현, 대조

int main()
{
	int size, x, y;

	scanf("%d", &size);
	scanf("%d %d", &x, &y);

	for (int i = 1; i <= x; ++i)
		for (int j = 1; j <= y; ++j)
			scanf("%c", &arr[i][j]);

	return 0;
=======
char arr[15][15];

int main()
{
	//ios::sync_with_stdio(false);

	int size, x, y;

	scanf("%d", &size);
	
	while (size--)
	{
		scanf("%d %d", &x, &y);

		for (int i = 1; i <= x; ++i)
		{
			cin.ignore();

			for (int j = 1; j <= y; ++j)
			{
				scanf("%c", &arr[i][j]);
			}

			for (int j = y; j >= 1; --j)
			{
				printf("%c", arr[i][j]);
			}

			printf("\n");
		}
	}

	return 0;

>>>>>>> fc31b687abe735a19d2015020be2e8be96974734
}