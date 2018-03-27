#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

bool arr[25];

int main()
{
    int n, num;
    char ins[50];

    scanf("%d", &n);

    while(n--)
    {
        scanf("%s %d\n", ins, &num);

        if(strcmp(ins, "add") == 0)
        {
            arr[num] = true;
        }
        else if(strcmp(ins, "remove") == 0)
        {
            arr[num] = false;
        }
        else if(strcmp(ins, "check") == 0)
        {
            if(arr[num])
                printf("1\n");
            else
                printf("0\n");
        }
        else if(strcmp(ins, "toggle") == 0)
        {
            if(arr[num])
                arr[num] = false;
            else
                arr[num] = true;
        }
        else if(strcmp(ins, "all") == 0)
        {
            for(int i = 1 ; i <= 20 ; ++i)
                arr[i] = true;
        }
        else if(strcmp(ins, "empty") == 0)
        { 
            for(int i = 1 ; i <= 20 ; ++i)
                arr[i] = false;
        }
    }
}