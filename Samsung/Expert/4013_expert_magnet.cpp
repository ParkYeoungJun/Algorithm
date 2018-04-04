#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int magnet[5][10];
int arrow[5];

int main()
{
    // k = 회전횟수, t = 출력번호
    int t = 0, testcase = 0, k;

    scanf("%d", &testcase);

    while (++t <= testcase)
    {
        int res = 0;

        scanf("%d", &k);

        for (int i = 1; i <= 4; ++i)
            for (int j = 0; j < 8; ++j)
                scanf("%d", &magnet[i][j]);

        for (int i = 0; i < k; ++i)
        {
            int tmp1, tmp2;
            scanf("%d %d", &tmp1, &tmp2);

            arrow[tmp1] = tmp2;

            if (tmp1 == 1)
            {
                for (int j = 2; j <= 4; ++j)
                {
                    if (magnet[j - 1][2] != magnet[j][6])
                        arrow[j] = arrow[j - 1] * (-1);
                    else
                        break;
                }
            }
            else if (tmp1 == 4)
            {
                for (int j = 3; j > 0; --j)
                {
                    if (magnet[j + 1][6] != magnet[j][2])
                        arrow[j] = arrow[j + 1] * (-1);
                    else
                        break;
                }
            }
            else if (tmp1 == 2)
            {
                if (magnet[2][6] != magnet[1][2])
                    arrow[1] = arrow[2] * (-1);

                for (int j = 3; j <= 4; ++j)
                {
                    if (magnet[j - 1][2] != magnet[j][6])
                        arrow[j] = arrow[j - 1] * (-1);
                    else
                        break;
                }
            }
            else
            {
                if (magnet[4][6] != magnet[3][2])
                    arrow[4] = arrow[3] * (-1);

                for (int j = 2; j > 0; --j)
                {
                    if (magnet[j + 1][6] != magnet[j][2])
                        arrow[j] = arrow[j + 1] * (-1);
                    else
                        break;
                }
            }

            for (int j = 1; j <= 4; ++j)
            {
                if (arrow[j] == 1)
                {
                    int tmp = magnet[j][7];
                    for (int k = 7; k > 0; --k)
                    {
                        magnet[j][k] = magnet[j][k - 1];
                    }
                    magnet[j][0] = tmp;
                }
                else if(arrow[j] == -1)
                {
                    int tmp = magnet[j][0];
                    for (int k = 0; k < 7; ++k)
                    {
                        magnet[j][k] = magnet[j][k + 1];
                    }
                    magnet[j][7] = tmp;
                }
            }

            memset(arrow, 0, sizeof(arrow));
        }

        for(int i = 1 ; i <= 4 ; ++i)
        {
            if(magnet[i][0] == 1)
            {
                res += pow(2.0, i-1);
            }
        }

        printf("#%d %d\n", t, res);
    }
    return 0;
}