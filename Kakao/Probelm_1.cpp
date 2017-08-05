#include <vector>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int dx[5] = {0, 0, 1, -1};
int dy[5] = {1, -1, 0, 0};

bool check[105][105] = {false,};

int bfs(int m, int n, int tx, int ty, vector<int>* picture)
{
    int cnt = 1;
    
    queue<pair<int, int> >  que;
    
    que.push(make_pair(tx, ty));

    while(!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;

        que.pop();

        cout << "x : " << x << " ";
        cout << "y : " << y << endl;

        for(int i = 0 ; i < 4 ; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !check[nx][ny])
            {
                if(picture[x][y] != picture[nx][ny])
                    continue;

                if(picture[x][y] == picture[nx][ny])
                {
                    check[nx][ny] = true;  
                    
                    que.push(make_pair(nx, ny));
                    
                    cnt++;
                }
            }
        }
    }
    
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<int>* picture) {
    int number_of_area = 0;
    int max_size_of_one_area = -1;
    
    for(int i = 0 ; i < m ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
        {
            if(!check[i][j] && picture[i][j] != 0)
            {
                check[i][j] = true;
                
                max_size_of_one_area = max(bfs(m,n,i,j,picture), max_size_of_one_area);
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    cout << number_of_area << endl;;
    cout << max_size_of_one_area;

    return answer;
}

int main()
{
    int m, n;
    vector<int> picture[105];

    scanf("%d %d", &m, &n);

    for(int i = 0 ; i < m ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
        {
            int temp;
            scanf("%d", &temp);

            picture[i].push_back(temp);
        }
    }

    solution(m, n, picture);
}