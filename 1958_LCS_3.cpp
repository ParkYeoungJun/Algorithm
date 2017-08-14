#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int dp[102][102][102];

int main()
{
    int size1, size2, size3;
    string input1, input2, input3;

    cin >> input1 >> input2 >> input3;

    input1 = '0' + input1;
    input2 = '0' + input2;
    input3 = '0' + input3;

    size1 = input1.size();
    size2 = input2.size();
    size3 = input3.size();

    for (int i = 1; i < size1; ++i)
    {
        for (int j = 1; j < size2; ++j)
        {
            for (int k = 1; k < size3; ++k)
            {
                if (input1.at(i) == input2.at(j) && input1.at(i) == input3.at(k) && input2.at(j) == input3.at(k))
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max( max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
            }
        }
    }

    printf("%d", dp[size1 - 1][size2 - 1][size3 - 1]);

    return 0;
}
