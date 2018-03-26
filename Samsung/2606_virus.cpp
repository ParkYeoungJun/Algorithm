#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int size, result;
int arr[105][105];
bool visit[105];

void dfs(int x)
{
    for(int i = 1 ; i <= size ; ++i) {
        if(arr[x][i] == 1 && !visit[i]) {

            visit[i] = true;
            result++;
            dfs(i);
        }
    }
}

int main()
{
    int n;
    memset(visit, false, sizeof(visit));

    scanf("%d", &size);
    scanf("%d", &n);

    for(int i = 0 ; i < n ; ++i) {
        int tmpX, tmpY;
        scanf("%d %d", &tmpX, &tmpY);

        arr[tmpX][tmpY] = 1;
        arr[tmpY][tmpX] = 1;
    }

    visit[1] = true;

    for(int i = 2 ; i <= size ; ++i) {
        if(arr[1][i] == 1 && !visit[i]) {
            visit[i] = true;
            result++;
            dfs(i);
        }
    }

    printf("%d", result);
}