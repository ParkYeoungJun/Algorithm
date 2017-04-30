#include<iostream>
#include<stdio.h>

using namespace std;

int main(void)
{
    int size, temp, count;

    scanf("%d", &size);

    count = size;

    for(int i = 0 ; i < size ; ++i)
    {
        scanf("%d", &temp);

        if(temp != 1 && temp != 0)
        {
            for(int j = 2 ; j < temp-1 ; ++j)
            {
                if(temp % j == 0)
                {
                     count--;
    
                     break;
                }
            }
        }
        else
        {
            count--;
        }
    }

    printf("%d\n", count);
}
