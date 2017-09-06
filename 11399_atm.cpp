#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;

int main()
{
    int n, res = 0;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; ++i)
    {
        int tmp;

        scanf("%d", &tmp);

        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    for(int i = 0 ; i < n ; ++i)
    {
        int tmp = 0; 

        for(int j = i ; j >= 0 ; --j)
            tmp += arr[j];

        res += tmp;
    }

    printf("%d", res);

}