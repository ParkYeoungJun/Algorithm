#include<iostream>
#include<stdio.h>

using namespace std;

int input[1000000];
int result[1000000];
int size;

void merge(int left, int right, int mid)
{
    int left_start = left;
    int left_end = mid;
    int right_start = mid+1;
    int right_end = right;
    int index = 0;

    while( (left_start <= left_end) && (right_start <= right_end) )
    {
        if( input[left_start] < input[right_start] )
        {
            result[index] = input[left_start];
            left_start++;
            index++;
        }
        else
        {
            result[index] = input[right_start];
            right_start++;
            index++;
        }
    }

    while(left_start <= left_end)
    {
        result[index] = input[left_start];
        left_start++;
        index++;
    }

    while(right_start <= right_end)
    {
        result[index] = input[right_start];
        right_start++;
        index++;
    }

    for(int i = 0 ; i < index ; ++i)
    {
        input[left] = result[i];
        left++;
    }

}

void mergesort(int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        mergesort(left, mid);
        mergesort(mid+1, right);
        merge(left, right, mid);
    }
}

int main(void)
{
//    std::ios::sync_with_stdio(false);

//    cin >> size; 
    scanf("%d", &size);

    if(size == 0)
        return 0;

    for(int i = 0 ; i < size ; ++i)
  //      cin >> input[i];
        scanf("%d", &input[i]);

    mergesort(0, size-1);

    for(int i = 0 ; i < size ; ++i)
  //        cout << input[i] << endl;
        printf("%d\n", input[i]);

    return 0;
}
