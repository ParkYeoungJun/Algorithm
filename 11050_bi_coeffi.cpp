#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int n, k, n_fac, k_fac, n_k_fac;

	scanf("%d %d", &n, &k);

	if(k == 0 || n-k == 0)
 		printf("1");
	else
	{
		n_fac = n, k_fac = k, n_k_fac = n-k;

		for(int i = n-1 ; i > 0 ; --i)
			n_fac *= i;

		for(int i = k-1 ; i > 0 ; --i)
			k_fac *= i;

		for(int i = n-k-1 ; i > 0 ; --i)
			n_k_fac *= i;

		printf("%d", n_fac/(k_fac*n_k_fac));
	}

	return 0;
}


