#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

vector<int> tree[100005];
int parent[100005];

int bfs()
{
    queue<int> que;

    que.push(1);

    while(!que.empty())
    {
        int temp = que.front();
        que.pop();

        for(int i = 0 ; i < tree[temp].size() ; ++i)
        {
            if(!parent[tree[temp].at(i)])
            {
                que.push(tree[temp].at(i));
                parent[tree[temp].at(i)] = temp;
            }
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; ++i)
    {
        int a, b;

        scanf("%d %d", &a, &b);

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    bfs();

    for(int i = 2 ; i <= n ; ++i)
        printf("%d\n", parent[i]);

    return 0;
}