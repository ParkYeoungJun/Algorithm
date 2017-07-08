#include<iostream>
#include<cstdio>

using namespace std;

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
}