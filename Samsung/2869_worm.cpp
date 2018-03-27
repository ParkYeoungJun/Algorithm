#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int noon, night, day, total, cnt=0;

    scanf("%d %d %d", &noon, &night, &total);

    day = noon - night;
    cnt = (total-noon) / day;

    if(total - noon <= 0) {
        printf("1");
    }
    else if(cnt*day+noon >= total) {
        printf("%d", cnt+1);
    }
    else {
        printf("%d", cnt+2);
    }

    
    return 0;
}