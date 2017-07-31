#include<iostream>
#include<cstdio>
#include<climits>
#include<vector>
#include<cmath>

using namespace std;

vector<int> tree[100005];
int dp[100005][20];
bool check[100005];
int l, mini;

void dfs(int index)
{
    for(int i = 1 ; i <= l ; ++i)
        dp[index][i] = i;

    for(int i = 0 ; i < tree[index].size() ; ++i)
    {
        int temp = tree[index].at(i);

        if(!check[temp])
        {
            check[temp] = true;

            dfs(temp);

            for(int i = 1 ; i <= l ; ++i)
            {
                mini = INT_MAX;

                for(int j = 1 ; j <= l ; ++j)
                {
                    if(i == j)
                        continue;

                    mini = min(mini, dp[temp][j]);
                }

                dp[index][i] += mini;
            }
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    l = log2(n);

    for(int i = 1 ; i < n ; ++i)
    {
        int a, b;

        scanf("%d %d", &a, &b);

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    check[1] = true;

    dfs(1);

    mini = INT_MAX;

    for(int i = 1 ; i <= l ; ++i)
    {
        mini = min(dp[1][i], mini);
    }

    printf("%d", mini);

    return 0;
}