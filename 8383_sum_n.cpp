#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n;
    long long int sum = 0;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; ++i)
        sum += i;

    printf("%lld", sum);
}
