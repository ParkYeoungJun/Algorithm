#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
 
int t,n,m,r,c,l,map[55][55],visit[55][55],ans;
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
 
void bfs()
{
    queue<pair<int,int>> q;
    visit[r][c]=true,ans++;
    q.push({r,c});
 
    while(--l)
    {
        int size=q.size();
        while(size--)
        {
            int x=q.front().first,y=q.front().second; q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m || visit[nx][ny])
                    continue;
 
                bool f=false;
                int a=map[x][y],b=map[nx][ny];
                if(a==1)
                {
                    if(i==0 && (b==1 || b==3 || b==4 || b==5))
                        f=true;
                    else if(i==1 && (b==1 || b==3 || b==6 || b==7))
                        f=true;
                    else if(i==2 && (b==1 || b==2 || b==4 || b==7))
                        f=true;
                    else if(i==3 && (b==1 || b==2 || b==5 || b==6))
                        f=true;
                }
                else if(a==2)
                {
                    if(i==2 && (b==1 || b==2 || b==4 || b==7))
                        f=true;
                    else if(i==3 && (b==1 || b==2 || b==5 || b==6))
                        f=true;
                }
                else if(a==3)
                {
                    if(i==0 && (b==1 || b==3 || b==4 || b==5))
                        f=true;
                    else if(i==1 && (b==1 || b==3 || b==6 || b==7))
                        f=true;
                }
                else if(a==4)
                {
                    if(i==1 && (b==1 || b==3 || b==6 || b==7))
                        f=true;
                    else if(i==3 && (b==1 || b==2 || b==5 || b==6))
                        f=true;
                }
                else if(a==5)
                {
                    if(i==1 && (b==1 || b==3 || b==6 || b==7))
                        f=true;
                    else if(i==2 && (b==1 || b==2 || b==4 || b==7))
                        f=true;
                }
                else if(a==6)
                {
                    if(i==0 && (b==1 || b==3 || b==4 || b==5))
                        f=true;
                    else if(i==2 && (b==1 || b==2 || b==4 || b==7))
                        f=true;
                }
                else if(a==7)
                {
                    if(i==0 && (b==1 || b==3 || b==4 || b==5))
                        f=true;
                    else if(i==3 && (b==1 || b==2 || b==5 || b==6))
                        f=true;
                }
 
                if(f) visit[nx][ny]=true,ans++,q.push({nx,ny});
            }
        }
    }
}
 
int main()
{
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d %d %d %d %d",&n,&m,&r,&c,&l);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            scanf("%d",&map[i][j]);
        bfs();
        printf("#%d %d\n",k,ans);
        memset(visit,0,sizeof(visit));
        ans=0;
    }
    return 0;
}