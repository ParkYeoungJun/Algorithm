#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int arr[15][15];
int visit[15];
int res;

vector<pair<int, int> > human;
vector<pair<int, int> > stair;
vector<int> stairA, stairB;
vector<bool> done;

queue<int> waitingA, waitingB;

int cal(int px, int py, int sx, int sy)
{
    return abs(px - sx) + abs(py - sy);
}

int find()
{
    vector<pair<int, int> > tmp;
    tmp = human;
    done.clear();
    stairA.clear();
    stairB.clear();

    int rtn = 0;

    while (done.size() < human.size())
    {
        for (int j = 0; j < stairA.size(); ++j)
        {
            stairA[j]--;

            if (stairA[j] == 0)
            {
                stairA.erase(stairA.begin() + j--);
                done.push_back(true);

                if (!waitingA.empty() && stairA.size() < 3)
                {
                    stairA.push_back(arr[stair[0].first][stair[0].second]+1);
                    waitingA.pop();
                }
            }
        }

        for (int j = 0; j < stairB.size(); ++j)
        {
            stairB[j]--;

            if (stairB[j] == 0)
            {
                stairB.erase(stairB.begin() + j--);
                done.push_back(true);

                if (!waitingB.empty() && stairB.size() < 3)
                {
                    stairB.push_back(arr[stair[1].first][stair[1].second]+1);
                    waitingB.pop();
                }
            }
        }

        for (int i = 0; i < tmp.size(); ++i)
        {
            if (visit[i] == 0)
            {
                if (tmp[i].first > 0)
                {
                    tmp[i].first--;

                    if (tmp[i].first == 0)
                    {
                        if (stairA.size() < 3)
                            stairA.push_back(arr[stair[0].first][stair[0].second]+1);
                        else
                            waitingA.push(1);
                    }
                }
            }
            else
            {
                if (tmp[i].second > 0)
                {
                    tmp[i].second--;

                    if (tmp[i].second == 0)
                    {
                        if (stairB.size() < 3)
                            stairB.push_back(arr[stair[1].first][stair[1].second]+1);
                        else
                            waitingB.push(1);
                    }
                }
            }
        }

        rtn++;
    }

    return rtn;
}

void tracking(int n, int size)
{
    if (n == size)
    {
        res = min(res, find());
    }
    else
    {
        visit[n] = 1;
        tracking(n + 1, size);
        visit[n] = 0;
        tracking(n + 1, size);
    }
}

int main()
{
    int t = 1, testcase;
    scanf("%d", &testcase);

    while (testcase--)
    {
        int n;
        scanf("%d", &n);
        stair.clear();
        human.clear();
        stairA.clear();
        stairB.clear();
        done.clear();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &arr[i][j]);

                if (arr[i][j] > 1)
                    stair.push_back(make_pair(i, j));
            }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (arr[i][j] == 1)
                {
                    int tmpA, tmpB;
                    pair<int, int> tmpPair;

                    tmpPair.first = cal(i, j, stair[0].first, stair[0].second);
                    tmpPair.second = cal(i, j, stair[1].first, stair[1].second);

                    human.push_back(tmpPair);
                }
            }

        res = INT_MAX;
        tracking(0, human.size());

        printf("#%d %d\n", t++, res);
    }

    return 0;
}