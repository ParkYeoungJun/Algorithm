#include<iostream>
#include<cstdio>
#include<malloc.h>

using namespace std;

#define min(a,b) ((a) < (b)) ? (a) : (b)

typedef struct _linked {
    int data;
    struct _linked* next = NULL;
} LINK;

int N;
int dp[1000002][2];
bool visit[1000002];
LINK* head[1000002];
LINK* tail[1000002];

void insert(int x, int y) {

    LINK* newNode = (LINK *) malloc(sizeof(LINK));
    newNode->data = y;
    newNode->next = NULL;

    if(head[x] == NULL) {
        head[x] = newNode;
        tail[x] = newNode;
    }
    else {
        LINK* tmp = tail[x];
        tail[x] -> next = newNode;
        tail[x] = newNode;
    }
}

void dfs(int s) {

    visit[s] = true;
    dp[s][0] = 0;
    dp[s][1] = 1;

    LINK* tmp = head[s];
    while(tmp != NULL) {
        if(!visit[tmp->data]) {
            dfs(tmp->data);
            dp[s][0] += dp[tmp->data][1];
            dp[s][1] += min(dp[tmp->data][0], dp[tmp->data][1]);
        }

        tmp = tmp->next;
    }

}

int main()
{
    scanf("%d", &N);

    for(int i = 0 ; i < N-1 ; ++i) {
        int tmpX, tmpY;
        scanf("%d %d", &tmpX, &tmpY);

        insert(tmpX, tmpY);
        insert(tmpY, tmpX);
    }

    dfs(1);
    printf("%d", min(dp[1][0], dp[1][1]));

    return 0;
}