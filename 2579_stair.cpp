#include<iostream>
#include<stdio.h>

using namespace std;

int main(void)
{
    int size;
    int array[302] = {0,};
    int dp[302] = {0,};

    scanf("%d", &size);

    for(int i = 1 ; i <= size ; ++i)
        scanf("%d", &array[i]);

    for(int i = 1 ; i <= 3 && i <= size ; ++i)
    {
        if(i < 3)
            dp[i] = array[i] + dp[i-1];
        else
            dp[i] = max(array[i] + dp[i-2], array[i] + array[i-1]);
    }

    for(int i = 4 ; i <= size ; ++i)
    {
        dp[i] = max(array[i] + dp[i-2], array[i] + array[i-1] + dp[i-3]);
    }

    printf("%d", dp[size]);
}
