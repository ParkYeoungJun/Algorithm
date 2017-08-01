#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<cstring>

using namespace std;

int l, depth[10005], level[10005], mini[10005], maxi[10005], child[10005];
vector<int> tree[10005];

void dfs(int index){

    int left = -1 , right = -1;

    if(tree[index].size() >= 2){

        left = tree[index][0];
        right = tree[index][1];

    }

    if(left != -1)
    {     
        depth[left] = depth[index] + 1;
        dfs(left);
    }

    level[index] = ++l;
 
    if(right!=-1) 
    {    
        depth[right] = depth[index] + 1;
        dfs(right);
    }

}

void bfs(int index){

    bool visit[10005]={0,};

    queue<int> que;

    que.push(index);

    visit[index]=true;

    int ret = 0;

    while(!que.empty()){

        int here = que.front();

        que.pop();

        for(int i = 0 ; i < tree[here].size() ; ++i){
            
            int next = tree[here].at(i);

            if(next == -1) 
                continue;

            ++ret;

            que.push(next);

            visit[next] = true;

        }

    }

    child[index] = ret;

}
int main(){

    int n;

    scanf("%d",&n);

    for(int i = 0 ; i < n ; ++i)
    {    
        int a, b, c;

        scanf("%d %d %d",&a,&b,&c);

        tree[a].push_back(b);
        tree[a].push_back(c);
    }

    int root = 0, val = 0;

    for(int i=1;i<=n;++i) 
        bfs(i);

    for(int i = 1 ; i <= n ; ++i)
         if(child[i] > val)
         {
             val = child[i];
             root = i;
         }

    depth[root] = 1;

    dfs(root);

    fill(mini , mini+n+1 , INT_MAX);

    for(int i = 1 ; i <= n ; ++i) {

        mini[depth[i]]=min(mini[depth[i]],level[i]);
        maxi[depth[i]]=max(maxi[depth[i]],level[i]);

    }

    int idx = 1, ans = 1;

    for(int i = 1 ; i <= n ; ++i){

        if(ans < maxi[i] - mini[i] + 1 ){
            idx = i;
            ans = maxi[i] - mini[i] + 1;
        }

    }

    printf("%d %d",idx,ans);
}
