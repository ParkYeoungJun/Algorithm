#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> arr;

int main()
{
    int n;
    int mini = 10000;
    int maxi = 0;

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
        maxi = max(arr[i]*(n-i), maxi);
    }

    printf("%d", maxi);
}