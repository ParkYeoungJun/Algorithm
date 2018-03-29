#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int arr[25][25];
int maxi[25];
bool visit[25];

int main()
{
    int t, n, x, count = 1;

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d %d", &n, &x);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            bool flag = true;
            memset(visit, false, sizeof(visit));

            for (int j = 0; j < n - 1; ++j)
            {
                if (arr[i][j] > arr[i][j + 1])
                {
                    if (arr[i][j] - arr[i][j + 1] > 1)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {

                        bool diff = true;
                        int k;

                        if (j + x >= n)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {

                            for (k = j + 1; k < x + j; ++k)
                            {
                                if (arr[i][k] != arr[i][k + 1])
                                {
                                    diff = false;
                                    break;
                                }
                            }

                            if (!diff)
                            {
                                flag = false;
                                break;
                            }
                            else
                            {
                                for (k = j + 1; k <= x + j; ++k)
                                {
                                    visit[k] = true;
                                }

                                j = k - 2;

                                continue;
                            }
                        }
                    }
                }
                else if (arr[i][j] < arr[i][j + 1])
                {
                    if (arr[i][j + 1] - arr[i][j] > 1)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        if (j - x + 1 < 0)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            bool diff = true;
                            int k;

                            for (k = j; k > j - x + 1; --k)
                            {
                                if (visit[k])
                                {
                                    flag = false;
                                    diff = false;
                                    break;
                                }

                                if (arr[i][k] != arr[i][k - 1])
                                {
                                    diff = false;
                                    break;
                                }
                            }

                            if (!diff)
                            {
                                flag = false;
                                break;
                            }
                        }
                    }
                }
            }

            if (flag)
            {
                cnt++;
            }
        }


        for (int i = 0; i < n; ++i)
        {
            bool flag = true;
            memset(visit, false, sizeof(visit));

            for (int j = 0; j < n - 1; ++j)
            {
                if (arr[j][i] > arr[j+1][i])
                {
                    if (arr[j][i] - arr[j+1][i] > 1)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {

                        bool diff = true;
                        int k;

                        if (j + x >= n)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {

                            for (k = j + 1; k < x + j; ++k)
                            {
                                if (arr[k][i] != arr[k+1][i])
                                {
                                    diff = false;
                                    break;
                                }
                            }

                            if (!diff)
                            {
                                flag = false;
                                break;
                            }
                            else
                            {
                                for (k = j + 1; k <= x + j; ++k)
                                {
                                    visit[k] = true;
                                }

                                j = k - 2;

                                continue;
                            }
                        }
                    }
                }
                else if (arr[j][i] < arr[j+1][i])
                {
                    if (arr[j+1][i] - arr[j][i] > 1)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        if (j - x + 1 < 0)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            bool diff = true;
                            int k;

                            for (k = j; k > j - x + 1; --k)
                            {
                                if (visit[k])
                                {
                                    flag = false;
                                    diff = false;
                                    break;
                                }

                                if (arr[k][i] != arr[k-1][i])
                                {
                                    diff = false;
                                    break;
                                }
                            }

                            if (!diff)
                            {
                                flag = false;
                                break;
                            }
                        }
                    }
                }
            }


            if (flag)
            {
                cnt++;
            }
        }

        printf("#%d %d\n", count, cnt);
        count++;
    }
}