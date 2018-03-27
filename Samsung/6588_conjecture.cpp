#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;
bool isPrime[1000005];

int main()
{
    int tmp, maxi = -1;

    while(true)
    {
        scanf("%d", &tmp);
    
        if(tmp == 0)
            break;
    
        arr.push_back(tmp);
        maxi = max(maxi, tmp);
    }

    for(int i = 2 ; i <= maxi ; ++i)
    {
        if(!isPrime[i])
        {
            for(int j = 2 ; i*j <= maxi ; ++j)
            {
                if(!isPrime[i*j])
                    isPrime[i*j] = true;    
            }
        }
    }

    isPrime[2] = true;

    for(int i = 0 ; i < arr.size() ; ++i)
    {
        int num = arr[i];

        for(int j = 3 ; j * 2 <= num ; j += 2)
        {
            if(!isPrime[j] && !isPrime[num - j])
            {
                printf("%d = %d + %d\n", num, j, num-j);
                break;
            }
        }
    }


}