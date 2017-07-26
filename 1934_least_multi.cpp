#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
	int size, n, k, maxi, mini;
	int iter = 1, temp;

	scanf("%d", &size);

	for(int i = 0 ; i < size ; ++i)
	{
		scanf("%d %d", &n, &k);
		maxi = max(n,k);
		mini = min(n,k);

		while(true)
		{
			temp = maxi * iter;

			if(temp % mini == 0)
			{
				printf("%d\n", temp);

				iter = 1;

				break;
			}	
			else
			{
				iter++;
			}
		}
	}

	return 0;
}

