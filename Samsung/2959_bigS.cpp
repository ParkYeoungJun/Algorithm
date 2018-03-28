#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > que;

int main()
{
    for(int i = 0 ; i < 4 ; ++i)
    {
        int tmp;
        scanf("%d ", &tmp);

        que.push(tmp);
    }

    int tor,tee;

    tor = que.top();

    que.pop();que.pop();

    tee = que.top();

    printf("%d", tor*tee);
}