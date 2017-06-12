#include<stdio.h>

int main(void)
{
	int b = 1;
	int a = 14;
	int k = 27;
	int n = 55;

	while(k > 0)
	{
		while(k % 2 == 0)
		{
			k = k/2;

			a = (a*a)%n;
		}

		k--;
		b = (b*a)%n;
	}

	printf("%d" , b);
}
