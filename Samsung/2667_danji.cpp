#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

queue<pair<int, int> > que;
priority_queue<int, vector<int>, greater<int> > sortQueue;
int arr[30][30], flag, n;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void BFS(int x, int y)
{
    int cnt = 1;

    que.push(make_pair(x,y));
    
    while(!que.empty()) 
    {
        pair<int, int> tmp = que.front();
        que.pop();

        for(int i = 0 ; i < 4 ; ++i) {
            int tmpX = tmp.first+dx[i], tmpY = tmp.second+dy[i];
        
            if(tmpX >= 0 && tmpX < n && tmpY >= 0 && tmpY < n)
            {
                if(arr[tmpX][tmpY] == -1){
                    arr[tmpX][tmpY] = flag;
                    que.push(make_pair(tmpX, tmpY));
                    cnt++;
                }
            }
        }
    }

    sortQueue.push(cnt);
}

int main()
{
    flag = 1;

    scanf("%d\n", &n);

    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j) {
            char tmp;
            scanf("%c\n", &tmp);
            
            arr[i][j] = tmp-48;
            if(arr[i][j] == 1)
                arr[i][j] = -1;
        }

    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)
        {
            if(arr[i][j] == -1) {
                arr[i][j] = flag;
                BFS(i, j);

                flag++;
            }
        }
    
    printf("%d\n", flag-1);
    for(int i = 0 ; i < flag-1 ; ++i) {
        printf("%d\n", sortQueue.top());
        sortQueue.pop();
    }

}