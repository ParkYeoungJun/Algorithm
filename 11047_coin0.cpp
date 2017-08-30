#include<bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<int>::iterator iter;

int main()
{
    int n, k, sum = 0;;

    scanf("%d %d", &n, &k);

    for(int i = 0 ; i < n ; ++i)
    {
        int tmp;

        scanf("%d", &tmp);

        arr.push_back(tmp);
    }

    iter = upper_bound(arr.begin(), arr.end(), k);

    --iter;

    for(; iter != arr.begin() ; --iter)
    {
        if(n == 0)
            break;

        sum += k / (*iter);

        k -= (k / (*iter)) * (*iter);
    }

    if(n != 0)
    {
        sum +=  k / (*arr.begin());
    }
    

    printf("%d", sum);

    return 0;
}
