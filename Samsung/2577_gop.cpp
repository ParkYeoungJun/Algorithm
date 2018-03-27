#include<iostream>
#include<cstdio>

using namespace std;

int arr[15];

int main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    long long ans = a*b*c;

    while(ans != 0)
    {
        arr[ans%10]++;
        ans /= 10;
    }

    for(int i = 0 ; i < 10 ; ++i)
        printf("%d\n", arr[i]);
}