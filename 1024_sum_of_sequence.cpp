#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int n, l, range, sum = 0, mini = 1000000;
	float start = 0;
	int p[3] = {0,};


	scanf("%d %d", &n, &l);

	range = l;

	while(true)
	{
		for(float j = range ; j <= 100 ; ++j)
		{
			sum = ((start + (start + j))/2) * (j+1);

			cout << "start : " << start << " j : " << j << " sum : " << sum << endl;

			if(sum > n)
			{
				start++;

				j = range-1;

				if(start > n)
					break;

				continue;
			}

			if(sum == n)
			{
				if(j < mini)
				{
					mini = j;

					p[0] = start;
					p[1] = j;

					if(j == l)
						goto finish;

				}
			}
		}

		start++;

		if(start > n)
		{
			break;
		}
	}


finish:

	
	if(mini != 1000000)
		for(int i = p[0] ; i <= p[0] + p[1] ; ++i)
			printf("%d ", i);
	else
		printf("-1");


	return 0;
}
