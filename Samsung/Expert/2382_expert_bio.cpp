#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

struct node {
    int x;
    int y;
    int num;
    int direct;
};

vector<node> arr;
vector<node> done;

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

bool flag[1005];

int main()
{
    int t = 1, testcase;
    scanf("%d", &testcase);

    while(testcase--)
    {
        int n, m, k, res = 0;
        arr.clear();

        scanf("%d %d %d", &n, &m, &k);

        for(int i = 0 ; i < k ; ++i)
        {
            int tmp1, tmp2, tmp3, tmp4;

            scanf("%d %d %d %d", &tmp1, &tmp2, &tmp3, &tmp4);

            node tmp;
            tmp.x = tmp1;
            tmp.y = tmp2;
            tmp.num = tmp3;
            tmp.direct = tmp4;

            arr.push_back(tmp);
        }

        for(int i = 0 ; i < m ; ++i)
        {
            for(int j = 0 ; j < arr.size() ; ++j)
            {
                int toX = arr[j].x + dx[arr[j].direct];
                int toY = arr[j].y + dy[arr[j].direct];
                
                node tmp;
                tmp.x = toX;
                tmp.y = toY;
                if(toX == 0 || toX == n-1 || toY == 0 || toY == n-1)
                {
                    arr[j].num /= 2;
                    
                    if(arr[j].direct == 1)
                        arr[j].direct = 2;
                    else if(arr[j].direct == 2)
                        arr[j].direct = 1;
                    else if(arr[j].direct == 3)
                        arr[j].direct = 4;
                    else if(arr[j].direct == 4)
                        arr[j].direct = 3;    
                }
                tmp.num = arr[j].num;
                tmp.direct = arr[j].direct;

                if(arr[j].num > 0)
                    done.push_back(tmp);
            }

            arr.clear();

            memset(flag, false, sizeof(flag));

            for(int j = 0 ; j < done.size() ; ++j)
            {
                int maxi = done[j].num;
                int direct = done[j].direct;
                int sum = done[j].num;
                if(flag[j])
                    continue;

                for(int k = j+1 ; k < done.size() ; ++k)
                {
                    if(j == k || flag[k])
                        continue;

                    if(done[j].x == done[k].x && done[j].y == done[k].y)
                    {
                        if(done[k].num > maxi)
                        {
                            direct = done[k].direct;
                            maxi = done[k].num;
                        }

                        sum += done[k].num;

                        flag[k] = true;
                    }    
                }

                node tmp;
                tmp.x = done[j].x;
                tmp.y = done[j].y;
                tmp.num = sum;
                tmp.direct = direct;

                arr.push_back(tmp);

            }

            done.clear();
        }

        for(int i = 0 ; i < arr.size() ; ++i)
            res += arr[i].num;

        printf("#%d %d\n", t++, res);
    }

    return 0;
}