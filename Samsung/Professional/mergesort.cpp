#include<iostream>
#include<cstdio>

using namespace std;

const int LM = (int)1e6;

int arr[LM + 5];
int sorted[LM + 5];

void merge(int s, int e, int mid) {
    int s1 = s, s2 = mid + 1, k = s;

    while(s1 <= mid && s2 <= e) {
        if(arr[s1] < arr[s2]) sorted[k++] = arr[s1++];
        else sorted[k++] = arr[s2++];
    } 

    if(s1 > mid) {
        for(int i = s2 ; i <= e ; ++i) {
            sorted[k++] = arr[i];
        }
    }
    else {
        for(int i = s1 ; i <= mid ; ++i) {
            sorted[k++] = arr[i];
        }
    }

    for(int i = s ; i <= e ; ++i)
        arr[i] = sorted[i];
}

void mergesort(int s, int e) {
    int mid;
    if(s < e) {
        mid = (s + e) / 2;
        mergesort(s, mid);
        mergesort(mid + 1 , e);  
        merge(s, e, mid);
    }

}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0 ; i < n ; ++i)
        scanf("%d", &arr[i]);

    mergesort(0, n-1);

    for(int i = 0 ; i < n ; ++i)
        printf("%d\n", arr[i]);

    return 0;
}