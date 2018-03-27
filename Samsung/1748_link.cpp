#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int sit = 0;
    long long n, tmp, ans, nine = 9;

    scanf("%lld", &n);

    tmp = n;
    while(tmp != 0){
        tmp/=10;
        sit++;
    }

    if(n >= 10)
        ans += nine;

    for(int i = 2 ; i < sit ; ++i)
    {
        nine *= 10;
        ans += i * nine;
    }
    
    tmp = 1;
    for(int i = 0 ; i < sit-1 ; ++i)
        tmp *= 10;
    n -= tmp;

    ans += sit * n;

    printf("%lld", ans+sit);
}