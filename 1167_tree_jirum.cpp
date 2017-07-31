#include<iostream>
#include<cstdio>
#include<string.h>
#include<vector>

using namespace std;

vector<pair<int, int> > tree [100005];
bool check[100005];
int maxi;
int root;

void dfs(int index, int sum)
{
    check[index] = true;

    if(maxi < sum)
    {
        maxi = sum;

        root = index;
    }

    for(int i = 0 ; i < tree[index].size() ; ++i)
    {
        if(check[tree[index].at(i).first] == false)
        {
            check[tree[index].at(i).first] = true;

            dfs(tree[index].at(i).first, sum + tree[index].at(i).second);
        }
    }
}


int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; ++i)
    {
        int a, b, c;

        scanf("%d", &a);

        while(true)
        {
            scanf("%d", &b);

            if(b == -1)
                break;

            scanf("%d", &c);

            tree[a].push_back(make_pair(b, c));
            tree[b].push_back(make_pair(a, c));
        }
    }

    maxi = -1;
    root = 0;

    dfs(1,0);

    maxi = -1;

    memset(check, false, sizeof(check));

    dfs(root, 0);

    printf("%d", maxi);

    return 0;
}