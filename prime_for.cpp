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

        if(i == 1 || i == 0)
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
            if(sum == 0)
                minimum = i;

            sum += i;
        }
    }

    if(sum != 0)
        printf("%d\n%d\n", sum, minimum);
    else
        printf("%d", -1);
}
