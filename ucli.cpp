#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
    int num_a, num_b;

    scanf("%d %d", &num_a, &num_b);

    for(int i = 1 ; i <= min(num_a, num_b) ; ++i)
    {
        if(num_a % i == 0 && num_b % i == 0)
            printf("%d ", i);
    }

    printf("\n");

    return 0;

}
