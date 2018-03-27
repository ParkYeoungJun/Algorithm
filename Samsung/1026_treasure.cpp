#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > aQueue;
priority_queue<int, vector<int>, less<int> > bQueue;

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; ++i)
    {
        int tmp;
        scanf("%d", &tmp);

        aQueue.push(tmp);
    }
    for(int i = 0 ; i < n ; ++i)
    {
        int tmp;
        scanf("%d", &tmp);

        bQueue.push(tmp);
    }

    int ans = 0;

    for(int i = 0 ; i < n ; ++i)
    {
        ans += aQueue.top() * bQueue.top();

        aQueue.pop();
        bQueue.pop();
    }

    printf("%d", ans);
}