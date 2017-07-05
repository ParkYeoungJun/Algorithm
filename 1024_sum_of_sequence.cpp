#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	long long n, l, sum = 0, result;

	scanf("%d %d", &n, &l);

	for (int i = 1; i < l; ++i)
		sum += i;

	for (; l <= 100; ++l)
	{
		if ((n - sum) % l == 0 && n >= sum)
		{
			result = (n - sum) / l;

			for (int i = 0; i < l; ++i)
				printf("%lld ", result + i);

			return 0;
		}

		sum += l;
	}

	printf("-1");

	return 0;
}