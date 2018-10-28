#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

int n, m, c;
int arr[15][15];
int visitA[15][15];
int visitB[15][15];
int dfsVisit[10];

pair<int, int> calc(vector<int> a, vector<int> b)
{
    int sumA = 0, sumB = 0;
    for (int i = 0; i < m; ++i)
    {
        if (dfsVisit[i] == 1)
        {
            sumA += a[i];
            sumB += b[i];
        }
    }

    pair<int, int> rtn;
    if(sumA <= c)
    {
        sumA = 0;
        for(int i = 0 ; i < m ; ++i)
        {  
            sumA += a[i] * a[i];
        }
    }
    else
        sumA = 0;
    if(sumB <= c)
    {
        sumB = 0;
        for(int i = 0 ; i < m ; ++i)
        {  
            sumB += a[i] * a[i];
        }
    }
    else
        sumB = 0;

    return make_pair(sumA, sumB);
}

int maxiA = INT_MIN;
int maxiB = INT_MIN;

void dfs(int val, vector<int> a, vector<int> b)
{
    if (val == m)
    {
        pair<int, int> rtn = calc(a,b);

        maxiA = max(maxiA, rtn.first);
        maxiB = max(maxiB, rtn.second);

        maxi = max(maxi, rtn.first + rtn.second);
    }
    else
    {
        dfsVisit[val] = 1;
        dfs(val + 1, a, b);
        dfsVisit[val] = 0;
        dfs(val + 1, a, b);
    }
}

void simulation()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j + m - 1 < n)
            {
                bool flag = true;

                for (int k = j; k <= j + m - 1; ++k)
                {
                    if (visitA[i][k] == 1)
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    memset(visitB, 0, sizeof(visitB));
                    

                    for (int k = j; k <= j + m - 1; ++k)
                    {
                        visitB[i][k] = 1;
                    }

                    vector<int> arrA;
                    vector<int> arrB;

                    for (int i = 0; i < n; ++i)
                    {
                        for (int j = 0; j < n; ++j)
                        {
                            if (visitA[i][j] == 1)
                                arrA.push_back(arr[i][j]);
                            if (visitB[i][j] == 1)
                                arrB.push_back(arr[i][j]);
                        }
                    }

                    dfs(0, arrA, arrB);
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
        scanf("%d %d %d", &n, &m, &c);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &arr[i][j]);

        int mx = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j + m - 1 < n)
                {
                    memset(visitA, 0, sizeof(visitA));

                    for (int k = j; k <= j + m - 1; ++k)
                    {
                        visitA[i][j] = 1;
                    }

                    simulation();
                    mx = max(maxi, mx);
                    memset(visitA, 0, sizeof(visitA));
                }
            }
        }

        printf("#%d %d\n", t++, mx);
    }
}