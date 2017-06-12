/*
 * koit.cpp
 *
 *  Created on: 2015. 10. 17.
 *      Author: Park
 */

#include<iostream>

using namespace std;

int** print;

void order(int group, int num_koi) {
    if (group == 1) {
        cout << num_koi << " ";
    }
    else {
        order(group-1, print[group][num_koi]);
        cout << num_koi-print[group][num_koi] << " ";
    }
}

int main(void)
{
     std::ios::sync_with_stdio(false);

    int* koi;
    int** dp;
    int num, group;

    cin >> num >> group;

    num++;
    group++;

    koi = new int [num];

    for(int i = 1 ; i <= num ; ++i)
        cin >> koi[i];

    dp = new int* [group];

    for(int i = 0 ; i < group ; ++i)
        dp[i] = new int[num];

    for(int i = 0 ; i < num ; ++i)
        for(int j = 0 ; j <= i ; ++j)
            dp[1][i] += koi[j];

    print = new int*[group];

    for(int i = 0 ; i < group ; ++i)
        print[i] = new int[num];

    int maxi;
    int min;
    int t_print;

    for(int i = 2 ; i < group ; ++i)
        for(int j = i ; j < num ; ++j){
            min = 10000;
            for(int k = i-1 ; k <= j ; ++k)
            {
                maxi = 0;

                for(int u = k+1 ; u <= j ; ++u)
                {
                    maxi += koi[u];
                }

                maxi = max(dp[i-1][k] , maxi);

                if(min > maxi)
                {
                    min = maxi;
                    t_print = k;
                }
            }
            dp[i][j] = min;
            print[i][j] = t_print;
        }

    cout << dp[group-1][num-1] << endl;
    order(group-1, num-1);
}

