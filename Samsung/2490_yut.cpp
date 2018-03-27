#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int cnt;

    for(int i = 0 ; i < 3 ; ++i)
    {
        cnt = 0;

        for(int j = 0 ; j < 4 ; ++j)
        {
            int tmp;
            scanf("%d", &tmp);

            if(tmp == 1)
                cnt++;
        }

        if(cnt == 0)
            printf("D\n");
        else if(cnt == 1)
            printf("C\n");
        else if(cnt == 2)
            printf("B\n");
        else if(cnt == 3)
            printf("A\n");
        else if(cnt == 4)
            printf("E\n");
    }

    return 0;
}