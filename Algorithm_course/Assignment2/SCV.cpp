/*
 * SCV.cpp
 *
 *  Created on: 2015. 10. 5.
 *      Author: Park
 */

#include<iostream>

using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);

    int num_col;
    int** arr;

    cin >> num_col;

    arr = new int*[num_col];

    for(int i = 0 ; i < num_col ; ++i)
    	arr[i] = new int[num_col];

    for(int i = 0 ; i < num_col ; ++i)
    	for(int j = 0 ; j < num_col ; ++j)
    		cin >> arr[i][j];

    int **dp;

    dp = new int*[num_col];
    for(int i = 0; i < num_col ; ++i)
    	dp[i] = new int[num_col];

    dp[0][0] = arr[0][0];

    for(int i = 1 ; i < num_col ; ++i)
    	dp[0][i] = dp[0][i-1]+arr[0][i];

    for(int i = 1 ; i < num_col ; ++i)
    	dp[i][0] = dp[i-1][0]+arr[i][0];

    for(int i = 1; i < num_col ; ++i)
    {
    	for(int j = 1 ; j < num_col ; ++j)
    	{
    		dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + arr[i][j];
    	}
    }

    cout << dp[num_col-1][num_col-1];
}
