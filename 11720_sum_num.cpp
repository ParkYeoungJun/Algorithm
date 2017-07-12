#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n, sum = 0;
    char temp;

    scanf("%d", &n);

    std::cin.ignore();

    for(int i = 0 ; i < n ; ++i)
    {
        scanf("%c", &temp);

        sum += (int)(temp-'0');
    }

    printf("%d", sum);
}
