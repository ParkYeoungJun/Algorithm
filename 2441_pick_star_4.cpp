#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = n ; i >= 1 ; --i)
    {
        for(int j = i ; j < n ; ++j)
            printf(" ");

        for(int j = 1 ; j <= i ; ++j)
            printf("*");

        printf("\n");
    }
}
