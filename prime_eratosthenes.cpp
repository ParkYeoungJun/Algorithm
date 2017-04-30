#include<iostream>
#include<stdio.h>

using namespace std;

int main(void)
{
    int from, to;
    bool array[1000002];
    array[1] = true;

    scanf("%d %d", &from, &to);

    for(int i = 2 ; i <= to ; ++i)
    {
        for(int j = 2 ; i*j <= to ; ++j)       
        {
            array[i*j] = true; 
        }

        if(i*2 > to)
            break;
    }

    for(int i = from ; i <= to ; ++i)
    {
        if(!array[i])
            printf("%d\n",i);
    }

}
