#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; ++i)
    {
        int tmp;
        scanf("%d", &tmp);

        arr.push_back(tmp);
    }

    if(prev_permutation(arr.begin(), arr.end()))
    {
        for(int i = 0 ; i < arr.size() ; ++i)
            printf("%d ", arr[i]);
    }
    else
        printf("-1");
}