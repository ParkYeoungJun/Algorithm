#include <stdio.h>
#include <iostream>
#include <climits>

using namespace std;

int n;

int oper[4];
int arr[15];

int visit[15];

int maxi, mini;

void dfs(int v, int num)
{
    // for(int i = 0 ; i < 4 ; ++i)
    //     printf("%d", oper[i]);
    // printf("\n");

   if (v == n) {
        maxi = max(maxi, num);
        mini = min(mini, num);
    }
    else {
        if (oper[0] != 0) {
            oper[0]--;
            dfs(v + 1, num + arr[v]);
            oper[0]++;
        }
        if(oper[1] != 0) {
            oper[1]--;
            dfs(v + 1, num - arr[v]);
            oper[1]++;
        }
        if (oper[2] != 0) {
            oper[2]--;
            dfs(v + 1, num * arr[v]);
            oper[2]++;
        }
        if (oper[3] != 0) {
            oper[3]--;
            dfs(v + 1, num / arr[v]);
            oper[3]++;
        }
    }
}

int main(void)
{
    int test_case;
    int T;

    setbuf(stdout, NULL);
    scanf("%d", &T);
    /*
	여러 개의 테스트 케이스를 처리하기 위한 부분입니다.
	*/
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d", &n);

        for (int i = 0; i < 4; ++i)
            scanf("%d", &oper[i]);

        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);

        maxi = INT_MIN;
        mini = INT_MAX;

        dfs(1, arr[0]);

        printf("#%d %d\n", test_case, maxi-mini);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}