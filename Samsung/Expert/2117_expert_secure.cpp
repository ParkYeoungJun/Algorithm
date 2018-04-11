#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>

using namespace std;

int arr[25][25];

int calc_cost(int k)
{
    return k * k + (k - 1) * (k - 1);
}

int **make_square(int k)
{
    int **array;

    array = (int **)malloc(sizeof(int *) * (k + k - 1));

    for (int i = 0; i < k + k - 1; ++i)
    {
        array[i] = (int *)malloc(sizeof(int) * (k + k - 1));
        memset(array[i], 0, sizeof(int) * (k + k - 1));
    }

    int x = 0, y = 0;

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k - i - 1; ++j)
            array[x][y++] = 0;

        for (int j = 0; j < i * 2 + 1; ++j)
            array[x][y++] = 1;

        x++;
        y = 0;
    }

    x = k + k - 2, y = 0;
    for (int i = 0; i < k - 1; ++i)
    {
        for (int j = 0; j < k - i - 1; ++j)
            array[x][y++] = 0;

        for (int j = 0; j < i * 2 + 1; ++j)
            array[x][y++] = 1;

        x--;
        y = 0;
    }

    return array;
}

int compare(int x, int y, int n, int m)
{
    int maxi = INT_MIN;
    for(int num = 2 ; num <= 21 ; ++num)
    {
        int** array = make_square(num);
        int cnt = 0;
        
        for(int i = 0 ; i < num + num - 1 ; ++i)
        {
            for(int j = 0 ; j < num + num - 1 ; ++j)
            {
                if(x-num+1+i >= 0 && y-num+1+j >= 0 && x-num+1+i < n && y-num+1+j < n)
                {
                    if(arr[x-num+1+i][y-num+1+j] == 1 && array[i][j] == 1)
                    {
                        cnt++;
                    }
                }
            }
        }

        if(m*cnt >= calc_cost(num))
        {
            maxi = max(cnt, maxi);
        }

        for(int i = 0 ; i < num+num-1 ; ++i)
            free(array[i]);
        free(array);
    }

    return maxi;
}

int main()
{
    int t = 1, testcase;
    scanf("%d", &testcase);

    while (testcase--)
    {
        int n, m, res = 0;
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &arr[i][j]);

        res = 1;
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < n ; ++j)
                res = max(compare(i, j, n, m), res);

        printf("#%d %d\n", t++, res);
    }

    return 0;
}