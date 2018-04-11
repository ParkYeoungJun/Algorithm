#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

// A = 0, B = 1

int array[25][25];
int inject[25];
int mini = INT_MAX;

bool search(int d, int w, int k)
{
    bool flag = true;

    for (int i = 0; i < w; ++i)
    {
        int tmp;
        if(inject[0] == 0)
            tmp = 0;
        else if(inject[0] == 1)
            tmp = 1;
        else if(inject[0] == -1)
            tmp = array[0][i];
        
        int cnt = 1;

        for (int j = 1; j < d; ++j)
        {
            if (inject[j] == 0)
            {
                if (tmp != 0)
                {
                    tmp = 0;
                    cnt = 1;
                }
                else
                {
                    cnt++;

                    if (cnt >= k)
                        break;
                }
            }
            else if (inject[j] == 1)
            {
                if (tmp != 1)
                {
                    tmp = 1;
                    cnt = 1;
                }
                else
                {
                    cnt++;

                    if (cnt >= k)
                        break;
                }
            }
            else if (inject[j] == -1)
            {
                if (tmp != array[j][i])
                {
                    tmp = array[j][i];
                    cnt = 1;
                }
                else
                {
                    cnt++;

                    if (cnt >= k)
                        break;
                }
            }
        }

        if (cnt < k)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

void solve(int d, int w, int k, int target, int type)
{
    inject[target] = type;

    if (target == d - 1)
    {
        if (search(d, w, k))
        {

            // for (int i = 0; i < d; ++i)
            //     cout << inject[i] << " ";
            // cout << endl;
            int cnt = 0;
            for (int i = 0; i < d; ++i)
                if (inject[i] != -1)
                    cnt++;
            mini = min(mini, cnt);
        }
    }
    else
    {
        solve(d, w, k, target + 1, -1);
        solve(d, w, k, target + 1, 0);
        solve(d, w, k, target + 1, 1);
    }
}

int main()
{
    int t = 1, testcase;

    scanf("%d", &testcase);

    while (testcase--)
    {
        int d, w, k;

        scanf("%d %d %d", &d, &w, &k);

        for (int i = 0; i < d; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                scanf("%d", &array[i][j]);
            }
        }

        solve(d, w, k, 0, -1);
        solve(d, w, k, 0, 0);
        solve(d, w, k, 0, 1);

        printf("#%d %d\n", t++, mini);
        mini = INT_MAX;
    }
}