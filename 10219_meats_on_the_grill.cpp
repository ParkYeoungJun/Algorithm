#include<iostream>
#include<cstdio>

using namespace std;

char arr[13][13];

// ������, 90��, 180��, 270�� �Լ� ����, ����

int main()
{
	int size, x, y;

	scanf("%d", &size);
	scanf("%d %d", &x, &y);

	for (int i = 1; i <= x; ++i)
		for (int j = 1; j <= y; ++j)
			scanf("%c", &arr[i][j]);

	return 0;
}