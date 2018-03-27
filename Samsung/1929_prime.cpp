#include <iostream>
#include <cstdio>

using namespace std;

bool arr[1000005];

int main()
{
    int from, to;

    scanf("%d %d", &from, &to);

    for (int i = 2; i <= to; ++i)
    {
        if (arr[i] == false)
        {
            for (int j = 2; i * j <= to; ++j)
            {
                arr[i*j] = true;
            }
        }
    }

    for(int i = from ; i <= to ; ++i) {
        if(!arr[i] && i > 1)
            printf("%d\n", i);
    }
}