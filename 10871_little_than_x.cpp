#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int x, y, temp;

    scanf("%d %d", &x, &y);

    for(int i = 0 ; i < x ; ++i)
    {
        scanf("%d", &temp);

        if(temp < y)
            printf("%d ", temp);
    }
}
