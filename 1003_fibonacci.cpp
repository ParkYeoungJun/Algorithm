#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

vector<pair<int,int> > fibo(50);


/*
int fibonacci(int n)
{
    if(n == 0)
    {
        ++zero;
        return 0;
    }
    else if(n == 1)
    {
        ++one;
        return 1;
    }
    else
        return fibonacci(n-1) + fibonacci(n-2);
}
*/

int main(void)
{
    int size, num;

    scanf("%d", &size);

    fibo[0] = make_pair(1, 0);
    fibo[1] = make_pair(0, 1);

    for(int i = 2 ; i <= 40 ; ++i)
    {
       fibo[i] = make_pair(fibo[i-1].first+fibo[i-2].first, fibo[i-1].second+fibo[i-2].second); 
    }

    for(int i = 0 ; i < size ; ++i)
    {
        scanf("%d", &num);

        printf("%d %d\n", fibo[num].first, fibo[num].second);
    }

}
