#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int n, jimin, hansu, count = 1;

	scanf("%d %d %d", &n, &jimin, &hansu);

	while(true)
	{
		if(jimin % 2 == 0)
		{
			if(hansu % 2 == 0)
			{
				jimin /= 2;

				hansu /= 2;

				count++;
			}
			else
			{
				if((hansu + 1)/2 == jimin/2 )
				{
					printf("%d", count);

					return 0;
				}
				else
				{
					jimin /= 2;

					hansu = (hansu + 1)/2; 

					count++;
				}
			}
		}
		else
		{
			if(hansu % 2 == 0)
			{
				if((jimin + 1)/2 == hansu/2)
				{
					printf("%d", count);

					return 0;
				}
				else
				{
					hansu /= 2;

					jimin = (jimin + 1)/2;

					count++;
				}
			}
			else
			{
				jimin = (jimin+1)/2;

				hansu = (hansu+1)/2;

				count++;
			}
		}

		if(count > (n+1)/2)
		{
			printf("-1");
		}
	}

	return 0;
}
