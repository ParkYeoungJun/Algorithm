#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int n, k;
int arr[10][10];
int visit[10][10];

vector<pair<int, int> > high;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int res = -1;

void dfs(int tmp[][10], int x, int y, int cnt)
{
    res = max(cnt, res);
    // if (cnt == 9)
    // {
    //     cout << "cnt : " << cnt << endl;
    //     cout << "x : " << x << " y : " << y << endl;
    //     for (int o = 0; o < n; ++o)
    //     {
    //         for (int g = 0; g < n; ++g)
    //         {
    //             cout << visit[o][g] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < 4; ++i)
    {
        int toX = x + dx[i], toY = y + dy[i];

        if (toX >= 0 && toX < n && toY >= 0 && toY < n)
        {
            if (tmp[x][y] > tmp[toX][toY])
            {
                visit[toX][toY] = 1;
                dfs(tmp, toX, toY, cnt + 1);
                visit[toX][toY] = 0;
            }
        }
    }
}

int main()
{
    int t = 1, testcase;
    scanf("%d", &testcase);

    while (testcase--)
    {
        scanf("%d %d", &n, &k);

        int maxi = -1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &arr[i][j]);
                maxi = max(arr[i][j], maxi);
            }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (arr[i][j] == maxi)
                    high.push_back(make_pair(i, j));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                int tmp[10][10];
                for (int l = 0; l < n; ++l)
                    for (int h = 0; h < n; ++h)
                        tmp[l][h] = arr[l][h];

                for (int h = 1; h <= k; ++h)
                {
                    tmp[i][j] = arr[i][j] - h;

                    for (int l = 0; l < high.size(); ++l)
                    {
                        if (!(i == high[l].first && j == high[l].second))
                        {
                            memset(visit, 0, sizeof(visit));
                            visit[high[l].first][high[l].second] = 1;

                            dfs(tmp, high[l].first, high[l].second, 1);
                        }
                    }
                }
            }

        printf("#%d %d\n", t++, res);
        res = -1;
        high.clear();
    }

    return 0;
}