#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    int n, case_n, temp;
    float aver = 0;
    vector<float> arr;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; ++i)
    {
        scanf("%d", &case_n);

        for(int j = 0 ; j < case_n ; ++j)
        {
            scanf("%d", &temp);

            arr.push_back(temp);

            aver += temp;
        }

        aver /= case_n;

        int cnt = 0;

        for(int j = 0 ; j < case_n ; ++j)
        {
            if(arr[j] > aver)
                cnt++;
        }

        printf("%.3f%%\n", cnt/(float)case_n * 100);

        arr.clear();

        aver = 0;
    }
}
