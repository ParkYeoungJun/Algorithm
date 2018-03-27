#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int arr[1000005];

void quicksort(int* arr, int left, int right)
{
    int &pivot = arr[left];
    int i = left + 1;
    int j = right;

    while(i <= j)
    {
        while(i <= right && arr[i] < pivot) i++;
        while(j >= left+1 && arr[j] > pivot) j--;

        if(i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    swap(pivot, arr[j]);
    if(left < j) quicksort(arr, left, j);
    if(right > i) quicksort(arr, i, right);
}

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; ++i)
    {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n-1);

    for(int i = 0 ; i < n ; ++i)
        printf("%d\n", arr[i]);
}