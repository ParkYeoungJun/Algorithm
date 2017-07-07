#include<iostream>
#include<cstdio>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		gcd(b, a%b);
}

int main()
{
	int size, a, b, x;

	scanf("%d", &size);

	while (size--)
	{
		scanf("%d %d", &a, &b);

		while (a != 1)
		{
			if (b % a == 0)
				x = b / a;
			else
				x = b / a + 1;

			a = a * x - b;
			b = x * b;

			int g = gcd(a, b);
			a /= g;
			b /= g;
		}

		printf("%d\n", b);
	}

	return 0;
}