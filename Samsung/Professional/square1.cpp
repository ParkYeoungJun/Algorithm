#include<iostream>
#include<cstdio>
#include<malloc.h>

#define max(a,b) ((a) > (b)) ? (a) : (b)

using namespace std;

int N, T;
int inArr[15];
int arr[15];
int maxi = -1;

void dfs(int n) {
    if(n == T){
        int sum1=0, sum2=0, sum3=0, sum4=0;

        for(int i = 0 ; i < T ; ++i) {
            if(arr[i] == 1) sum1+=inArr[i];
            else if(arr[i] == 2) sum2+=inArr[i];
            else if(arr[i] == 3) sum3+=inArr[i];
            else sum4+=inArr[i];   
        }

        if(sum1 == sum2) {
            if(sum3 == sum4) {
                maxi = max(sum1 * sum3, maxi);
            }
        }
        else if(sum1 == sum3) {
            if(sum2 == sum4){
                maxi = max(sum1 * sum2, maxi);
            }
        }
        else if(sum1 == sum4) {
            if(sum2 == sum3){
                maxi = max(sum1 * sum2, maxi);
            }
        }

        return;
    }

    for(int i = 1 ; i <= 4 ; ++i) {
        arr[n] = i;
        dfs(n + 1);
    }
}

int main()
{
    scanf("%d", &N);

    while(N--) {

        scanf("%d", &T);

        int sum = 0;
        for(int i = 0 ; i < T ; ++i){    
            scanf("%d", &inArr[i]);
            sum += inArr[i];
        }

        dfs(0);

        if(maxi == -1) {
            printf("%d\n" , 0);
        }
        else printf("%d\n", maxi);

        maxi = -1;
    }

    return 0;
}