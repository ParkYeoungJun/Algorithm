#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    int n, temp, maxi = -1;
    float sum = 0;
    vector<float> arr;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; ++i)
    {
        scanf("%d", &temp);

        arr.push_back(temp);

        maxi = max(maxi, temp);
    }

    for(vector<float>::iterator iter = arr.begin() ; iter != arr.end() ; ++iter)
    {
        sum += (*iter)/maxi * 100;
    }

    printf("%.2f", sum/(float)n);
}
