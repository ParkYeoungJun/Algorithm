#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
    int sum_all = 0;
    int input[10] = {0,};

    for(int i = 0 ; i < 9 ; ++i)
    {
        int temp;

        scanf("%d", &temp);

        sum_all += temp;

        input[i] = temp;
    }

    sort(input, input+9);

    for(int i = 0 ; i < 9 ; ++i)
    {
        for(int j = i+1 ; j < 9 ; ++j)
        {
            if(sum_all - input[i] - input[j] == 100)
            {
                for(int k = 0 ; k < 9 ; ++k)
                {
                    if(k != i && k != j)
                    {
                        printf("%d\n", input[k]);
                    }
                }
            }
        }
    }

    

	return 0;
}
