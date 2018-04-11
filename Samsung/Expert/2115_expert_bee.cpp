#include <iostream>
#include <cstdio>
#include <vector>
#include<cstring>
#include <algorithm>

using namespace std;

int arr[15][15];
int visit[15][15];

int tracVisit[15];

int calc(int x, int y, int c, int m)
{
    int sum = 0;
    for(int i = y ; i < y + m ; ++i)
    {
        if(tracVisit[i-y] == 1)
        {
            sum += arr[x][i];
        }
    }

    if(sum > c)
        return 0;
    else
    {
        int rtn = 0;
        for(int i = y ; i < y + m ; ++i)
        {
            if(tracVisit[i-y] == 1)
            {
                rtn += arr[x][i] * arr[x][i];
            }
        }

        return rtn;
    }
}

int mx = -1;
void tracking(int x, int y, int m, int n, int c, int val)
{
    if(val == m)
    {
        mx = max(calc(x, y, c, m), mx);
        // cout << "x: " << x << " y : " << y << endl;
        // cout << calc(x, y, c, m) << endl;
    }
    else
    {
        tracVisit[val] = 1;
        tracking(x, y, m , n, c, val + 1);
        tracVisit[val] = 0;
        tracking(x, y, m, n, c, val + 1);
    }
}

int search(int x, int y, int n, int m, int c)
{
    mx = -1;
    memset(tracVisit, 0, sizeof(tracVisit));
    tracking(x, y, m, n, c, 0);

    int sum = mx;
    int maxi = -1;
    int tmp = mx;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j + m - 1 < n)
            {
                bool flag = false;
                for(int k = j ; k < j + m ; ++k)
                {
                    if(visit[i][k] == 1)
                    {
                        flag = true;
                    }
                }

                if(!flag)
                {

                    mx = -1;
                    memset(tracVisit, 0, sizeof(tracVisit));
                    tracking(i, j, m, n, c, 0);

                    sum += mx;

                    maxi = max(sum, maxi);

                    sum = tmp;
                }
            }
        }
    }

    return maxi;
}

int main()
{
    int t = 1, testcase;
    scanf("%d", &testcase);

    while (testcase--)
    {
        int n, m, c;
        scanf("%d %d %d", &n, &m, &c);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &arr[i][j]);

        int maxi = -1;
        for (int i = 0; i < n; ++i)
        {
            // 첫 농부의 시작점
            for (int j = 0; j < n; ++j)
            {
                if (j + m - 1 < n)
                {
                    for (int k = j; k < j + m; ++k)
                    {
                        visit[i][k] = 1;
                    }

                    maxi = max(search(i, j, n, m, c), maxi);
                    memset(visit, 0, sizeof(visit));
                }
            }
        }

        printf("#%d %d\n", t++, maxi);
    }
    return 0;
}