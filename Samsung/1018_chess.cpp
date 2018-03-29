#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

char w[9][9];
char b[9][9];
char arr[50][55];

int main()
{
    int n, m;

    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%c\n", &arr[i][j]);

    char wTmp = 'W';
    char bTmp = 'B';
    for (int i = 0; i < 8; ++i)
    {

        w[i][0] = wTmp;
        b[i][0] = bTmp;

        for (int j = 1; j < 8; ++j)
        {
            if (w[i][j - 1] == 'W')
                w[i][j] = 'B';
            else
                w[i][j] = 'W';

            if (b[i][j - 1] == 'W')
                b[i][j] = 'B';
            else
                b[i][j] = 'W';
        }

        if (wTmp == 'W')
            wTmp = 'B';
        else
            wTmp = 'W';

        if (bTmp == 'W')
            bTmp = 'B';
        else
            bTmp = 'W';
    }

    int mini = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i + 8 <= n && j + 8 <= m)
            {
                int wCnt = 0, bCnt = 0;
                for (int k = 0; k < 8; ++k)
                {
                    for (int h = 0; h < 8; ++h)
                    {
                        if(w[k][h] != arr[k+i][h+j])
                            wCnt++;

                        if(b[k][h] != arr[k+i][h+j])
                            bCnt++;
                    }
                }

                int tmp = min(wCnt, bCnt);
                mini = min(tmp, mini);
            }
        }
    }

    printf("%d", mini);
}