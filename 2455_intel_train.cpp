#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
	int in, out, maxi = 0,current = 0;

	for(int i = 0 ; i < 4 ; ++i)
	{
		scanf("%d %d", &in, &out);

		current -= in;
		current += out;

		maxi = max(current, maxi);
	}

	printf("%d", maxi);

	return 0;
}
