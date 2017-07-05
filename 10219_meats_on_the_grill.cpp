#include<iostream>
#include<cstdio>

using namespace std;

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

}