#include<stdio.h>
#include<iostream>

using namespace std;

bool array[2000002];

int main(void)
{
    int size;
    int temp;

    scanf("%d", &size);

    if(size == 0)
        return 0;
    else if(size == 1)
    {
        scanf("%d", &size);
        printf("%d\n", size);
        return 0;
    }

    for(int i = 0 ; i < size ; ++i)
    {
        scanf("%d", &temp);

        temp += 1000000;

        array[temp] = true;
    }

    for(int i = 0 ; i < 2000002 ; ++i)
    {
       if(array[i]) 
       {
           printf("%d\n", i-1000000);
       }

    }
}
