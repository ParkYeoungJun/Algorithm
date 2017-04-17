#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int x, count = 0;
	int heigh[8] = {64, 32, 16, 8, 4, 2, 1};

	scanf("%d", &x);

	for(int i = 0 ; i < 8 ; ++i)
	{
		if(x >= heigh[i])
		{
			count++;

			x = x - heigh[i];
		}

		if(x == 0)
			break;
	}

	printf("%d", count);

	return 0;
}
