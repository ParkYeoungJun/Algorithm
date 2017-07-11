#include<iostream>
#include<cstdio>

using namespace std;

int dp[5002];

int main()
{
    int a;

    cin >> a;


    for(int i = 0 ; i <= a ; ++i)
    {
        if(i == 0 || i == 1 || i == 2 || i == 4)
        {
            dp[i] = -1;
        }
        else if(i == 3 || i == 5)
        {
            dp[i] = 1;
        }
        else
        {
            if(dp[i-5] != -1 && dp[i-3] != -1)
                dp[i] = dp[i-5] > dp[i-3] ? dp[i-3]+1 : dp[i-5]+1;
            else if(dp[i-5] == -1 && dp[i-3] != -1)
                dp[i] = dp[i-3]+1;
            else if(dp[i-5] != -1 && dp[i-3] == -1)
                dp[i] = dp[i-5]+1;
            else
                dp[i] = -1;

        }
    }

    cout << dp[a];
}
