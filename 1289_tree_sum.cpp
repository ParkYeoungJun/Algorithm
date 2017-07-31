#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define mod 1000000007

vector<pair<int, int> > tree[100005];
int result;

long long dfs(int index, int to)
{
    long long ret = 1;

    for (int i = 0; i < tree[index].size(); ++i)
    {
        if (tree[index].at(i).first == to)
            continue;

        long long t = (long long)dfs(tree[index].at(i).first, index) * tree[index].at(i).second % mod;

        result = (result + t * ret) % mod;

        ret = (ret + t) % mod;
    }

    return ret;
}


int main()
{
    int n;

    scanf("%d", &n);

    for (int i = 1; i < n; ++i)
    {
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);

        tree[a].push_back(make_pair(b, c));
        tree[b].push_back(make_pair(a, c));
    }

    dfs(1, -1);

    printf("%d", result);

    return 0;
}