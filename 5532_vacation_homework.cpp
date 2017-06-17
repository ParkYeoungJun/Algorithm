#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int l, a, b, c, d;

	scanf("%d%d%d%d%d", &l, &a, &b, &c, &d);

	if (a == 0 && b == 0)
	{
		printf("%d", l);

		return 0;
	}

	while (true)
	{
		a -= c;
		b -= d;
		l--;

		if (l == 0)
		{
			printf("0");
		
			return 0;
		}

		if (a <= 0 && b <= 0)
		{
			printf("%d", l);

			return 0;
		}
	}
}