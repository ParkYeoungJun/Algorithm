#include <vector>
#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

#define mod 20170805
    
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<int>* city_map) {
    
    int arr[505][505] = {0,};

    for(int i = 0; i < m; ++i){
        
        if(city_map[i][0] == 1)
             break;
    
        arr[i][0] = 1;
    }

    for(int i = 0 ; i < n ; ++i){
        
        if(city_map[0][i]==1) 
            break;
        
        arr[0][i]=1;
    
    }

    for(int i = 1 ; i < m ; ++i)
    {
        for(int j = 1 ; j < n ; ++j)
        {
            if(city_map[i][j] != 1)
            {
                for(int k = 1 ; i-k >= 0 ; ++k)
                {
                    if(city_map[i-k][j] == 1)
                    {
                        break;
                    }
                
                    if(city_map[i-k][j] == 0)
                    {
                        arr[i][j] += arr[i-k][j];
                        arr[i][j] %= mod;

                        break;
                    }
                }

                for(int k = 1 ; j-k >= 0 ; ++k)
                {
                    if(city_map[i][j-k] == 1)
                    {
                        break;
                    }
                
                    if(city_map[i][j-k] == 0)
                    {
                        arr[i][j] += arr[i][j-k];
                        arr[i][j] %= mod;

                        break;
                    }
                }
                
            }
        }
    }
    
    for(int i = 0 ; i < m ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
            cout << arr[i][j] << " ";
        
        cout << endl;
    }
    
    int answer = arr[m-1][n-1];
    return answer;
}

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);

    vector<int> city[505];

    for(int i = 0 ; i < m ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
        {
                int temp;
            scanf("%d", &temp);

            city[i].push_back(temp);

        }
    }

    cout << "re : " << solution(m,n,city) << endl;
}