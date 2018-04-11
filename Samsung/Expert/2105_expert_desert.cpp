#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[25][25];
int visit[25][25];
vector<int> memo;

int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};

int maxi = -1;

void dfs(int fromX, int fromY, int x, int y, int direct)
{
    // cout << "direct : " << direct << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //         cout << visit[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;

    // 처음
    if (fromX == x && fromY == y && direct == 0)
    {
        int toX = x + dx[0], toY = y + dy[0];

        if (toX >= 0 && toX < n && toY >= 0 && toY < n && visit[toX][toY] == 0)
        {
            if (arr[x][y] != arr[toX][toY])
            {
                visit[toX][toY] = 1;
                memo.push_back(arr[toX][toY]);

                dfs(fromX, fromY, toX, toY, 0);
            }
        }
    }
    else
    {
        for (int i = direct; i <= direct + 1 && i < 4; ++i)
        {
            int toX = x + dx[i], toY = y + dy[i];
            // cout << "i : " << i << endl;

            if (toX == fromX && toY == fromY && i == 3)
            {
                int tmp = memo.size();
                maxi = max(maxi, tmp);
            }

            if (toX >= 0 && toX < n && toY >= 0 && toY < n && visit[toX][toY] == 0)
            {
                // cout << "toX : " << toX << " toY : " << toY << endl;
                // // for (int k = 0; k < memo.size(); ++k)
                // //     cout << memo[k] << " ";
                // cout << endl;
                // cout << "arr[][] : " << arr[toX][toY] << endl;
                // cout << endl;
                vector<int>::iterator iter = find(memo.begin(), memo.end(), arr[toX][toY]);
                if (iter == memo.end())
                {
                    visit[toX][toY] = 1;
                    memo.push_back(arr[toX][toY]);

                    dfs(fromX, fromY, toX, toY, i);
                    visit[toX][toY] = 0;
                    memo.erase(memo.end()-1);
                }
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
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &arr[i][j]);

        maxi = -1;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                memset(visit, 0, sizeof(visit));
                
                visit[i][j] = 1;
                
                memo.push_back(arr[i][j]);

                dfs(i, j, i, j, 0);

                memo.clear();
            }

        printf("#%d %d\n", t++, maxi);
    }

    return 0;
}