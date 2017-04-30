#include<iostream>
#include<stdio.h>

using namespace std;

int main(void)
{
    int from, to, minimum, sum = 0;

    scanf("%d", &from);
    scanf("%d", &to);

    for(int i = from ; i <= to ; ++i)
    {
        bool whe = true;

        if(i == 1)
            continue;

        for(int j = 2 ; j < i ; ++j)
        {
            if(i % j == 0)
            {
                whe = false;
                break;
            }
        }

        if(whe)
        {
            printf("%d\n", i);
        }
    }
}
