#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int dp[1002][1002];

int main()
{
    int size1, size2;
    string input1, input2;

    cin >> input1 >> input2;

    input1 = '0' + input1;
    input2 = '0' + input2;

    size1 = input1.size();
    size2 = input2.size();

    for(int i = 1 ; i < size1 ; ++i)
    {
        for(int j = 1 ; j < size2 ; ++j)
        {
            if(input1.at(i) == input2.at(j))
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    printf("%d", dp[size1 - 1][size2 - 1]);

    return 0;
}
