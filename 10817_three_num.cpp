#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int a, b, c, big;

    scanf("%d %d %d", &a, &b, &c);

    big = max(a, b);
    big = max(big, c);

    if(big == a)
        printf("%d", max(b,c));
    else if(big == b)
        printf("%d", max(a,c));
    else
        printf("%d", max(a,b));
}
