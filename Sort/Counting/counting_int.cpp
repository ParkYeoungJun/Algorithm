#include<iostream>
#include<stdio.h>

using namespace std;

int main(void)
{
    int input[10002] = {0};
    int size;
    int temp;

    scanf("%d", &size);

    if(size == 0)
        return 0;

    for(int i = 0 ; i < size ; ++i)
    {
        scanf("%d", &temp);

        input[temp]++;
    }

    for(int i = 0 ; i <= 10000 ; ++i)
    {
        if(input[i] > 0)
        {
            printf("%d\n", i);
            input[i]--;
            i--;
        }
    }

}
