#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> arr;
int dp[1005];
bool memo[1005];

int main()
{
    int n, maxi = -1;

    scanf("%d", &n);

    while(n--)
    {
        int tmp;
        scanf("%d", &tmp);

        if(maxi < tmp)
            maxi = tmp;

        arr.push_back(tmp);
    }

    int tee = 2, iter = 1;
    dp[0] = 1;
    while(true)
    {
        dp[iter] = dp[iter-1] + tee;

        if(dp[iter] > maxi)
            break;

        tee++;
        iter++;
    }


    for(int i = 0 ; i <= iter ; ++i)
        for(int j = 0 ; j <= iter ; ++j)
            for(int k = 0 ; k <= iter ; ++k)
            {
                int tmp = dp[i] + dp[j] + dp[k];

                if(tmp <= 1000)
                    memo[tmp] = true;
                else
                    break;
            }

    for(int i = 0 ; i < arr.size() ; ++i)
    {
        if(memo[arr[i]])
            printf("1\n");
        else
            printf("0\n");
    }

}