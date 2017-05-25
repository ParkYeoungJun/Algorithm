#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int size, ball = 1, x, y;

	scanf("%d", &size);

	for(int i = 0 ; i < size ; ++i)
	{
		scanf("%d %d", &x, &y);

		if(ball == x)
		{
			ball = y;
		}
		else if(ball == y)
		{
			ball = x;
		}
	}

	printf("%d", ball);

	return 0;
}
