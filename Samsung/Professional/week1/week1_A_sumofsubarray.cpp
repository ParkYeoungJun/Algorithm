//#include<iostream>
#include<cstdio>

//using namespace std;

int N, M;
long long int arr[1005][1005];

int main()
{
    scanf("%d", &N);

    for(int i = 1 ; i <= N ; ++i) 
        for(int j = 1 ; j <= N ; ++j) {
            scanf("%lld", &arr[i][j]);
            arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]; 
        }

    scanf("%d", &M);

    int sri, sci, eri, eci;
    for(int i = 0 ; i < M ; ++i)  {
        scanf("%d %d %d %d", &sri, &sci, &eri, &eci);
        printf("%lld\n", arr[eri][eci] - arr[sri-1][eci] - arr[eri][sci-1] + arr[sri-1][sci-1]);
    }

    return 0;
}