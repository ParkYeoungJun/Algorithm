#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int arr[1002][1002];
int ans[1002][1002];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int BFS(queue<pair<int, int> > que, int m, int n) 
{
    while(!que.empty()) 
    {
        pair<int, int> tmpPair = que.front();
        que.pop();

        // cout << endl;
        // for(int i = 0 ; i < m ; ++i) {
        //     for(int j = 0 ; j < n ; ++j)
        //         cout << ans[i][j] << " ";
        //     cout << endl;
        // }
        // cout << endl;

        for(int i = 0 ; i < 4 ; ++i) {
            int tmpX = tmpPair.first + dx[i], tmpY = tmpPair.second + dy[i];

            if(tmpX >= 0 && tmpX < m && tmpY >= 0 && tmpY < n) {
                if(arr[tmpX][tmpY] == 0) {
                    que.push(make_pair(tmpX, tmpY));
                    arr[tmpX][tmpY] = 1;
                    ans[tmpX][tmpY] = ans[tmpPair.first][tmpPair.second] + 1;
                }
            }
        }
    }

    int maxi = -1;

    for(int i = 0 ; i < m ; ++i) {
        for(int j = 0 ; j < n ; ++j) {
            if(ans[i][j] == 0)
                return -1;
            else
                maxi = max(ans[i][j], maxi);
        }
    }

    return maxi-1;
}

int main() 
{
    int n, m;
    queue<pair<int, int> > que;

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < m ; ++i)
        for(int j = 0 ; j < n ; ++j) {
            scanf("%d", &arr[i][j]);
            ans[i][j] = arr[i][j];
            
            if(arr[i][j] == 1) {
                que.push(make_pair(i, j));
            }
        }

    if(que.size() == 0)
        printf("%d", -1);
    else if(que.size() == m*n)
        printf("%d", 0);
    else
        printf("%d", BFS(que, m, n));

    return 0;
}