#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int total = 1000, cnt = 0, cost;

    scanf("%d", &cost);

    total = total - cost;

    cnt += total / 500;
    total -= 500 * (total / 500);
    cnt += total / 100;
    total -= 100 * (total / 100);
    cnt += total / 50;
    total -= 50 * (total / 50);
    cnt += total / 10;
    total -= 10 * (total / 10);
    cnt += total / 5;
    total -= 5 * (total / 5);
    cnt += total;

    printf("%d", cnt);

    return 0;
}