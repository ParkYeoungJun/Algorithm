#include<iostream>
#include<queue> 
#include<stdio.h>
#include<string.h>

using namespace std;

int dot,line,start;
int graph[1020][1020];
bool check[1020];

void dfs(int s)
{
    check[s] = true;
    printf("%d ", s);

    for(int i = 1 ; i <= dot ; ++i)
    {
        if(graph[s][i] == 1 && !check[i])
            dfs(i);
    }
}

void bfs(int s)
{
    check[s] = true;
    queue<int> q;
    q.push(s);
    int temp;

    while(!q.empty())
    {
        temp = q.front();
        printf("%d ", temp);
        q.pop();

        for(int i = 1 ; i <= dot ; ++i)
        {
            if(graph[temp][i] == 1 && !check[i])
            {
                check[i] = true;
                q.push(i);
            }
        }
    }
}

int main(void)
{
    scanf("%d %d %d", &dot, &line, &start);

    for(int i = 0 ; i < line ; ++i)
    {
        int begin, end;
        scanf("%d %d", &begin, &end);

        graph[begin][end] = graph[end][begin] = 1;
    }

    dfs(start);
    memset(check, false, 1020);
    printf("\n");
    bfs(start);

    return 0;
}
