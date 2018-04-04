#include<iostream>
#include<cstdio>
#include<climits>
#include<cmath>
#include<vector>
#include<cstring>

using namespace std;

int arr[20][20];
bool visit[20];

int n, result = INT_MAX;

int calc(vector<int> t)
{
    int rtn = 0;

    for(int i = 0 ; i < n/2 ; ++i)
    {
        for(int j = 0 ; j < n/2 ; ++j)
        {
            if(i == j) continue;
            rtn += arr[t[i]][t[j]];
        }
    }

    return rtn;
}

int getRes()
{
    vector<int> a;
    vector<int> b;

    for(int i = 0 ; i < n ; ++i)
    {
        if(visit[i])
            a.push_back(i);
        else
            b.push_back(i);
    }

    return abs(calc(a) - calc(b));
}

void tracking(int v, int cnt)
{
    visit[v] = true;

    if(cnt == n/2)
    {
        result = min(getRes(), result);
    }
    else
    {
        for(int i = v + 1 ; i < n ; ++i)
        {
            tracking(i, cnt+1);
        }
    }

    visit[v] = false;
}

int main()
{
    int t=0,testcase;
    
    scanf("%d", &testcase);

    while(++t <= testcase)
    {
        scanf("%d", &n);

        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < n ; ++j)
                scanf("%d", &arr[i][j]);

        tracking(0,1);

        printf("#%d %d\n", t, result);

        memset(visit, false, sizeof(visit));
    
        result = INT_MAX;
    }
}