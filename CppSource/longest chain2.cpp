#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#define Max 1000012
#define re register
struct tree
{
    int next,to,dis;
}t[Max];
int cnt,n,ans=0,node,head[Max],dis[Max];
bool vis[Max]={0};

void add(int u,int v,int w)
{
    t[++cnt].next=head[u];
    t[cnt].to=v;
    t[cnt].dis=1;
    head[u]=cnt;
 }
void dfs(int x,int p){
    for(re int i = head[x] ; i ; i = t[i].next) {
       int v = t[i].to;
       if(vis[v]) continue;
         vis[v]=1;
      dis[v] = p + t[i].dis;
       if(dis[v] > ans) {
            ans=dis[v];
            node=v;
        }
        dfs(v,dis[v]);
    }
}
 int main()
 {
    scanf("%d",&n);
    int x,y;
    for(re int i = 1 ; i <= n ; ++ i) {
         scanf("%d%d",&x,&y);
       if(y!=0)
             add(i,y,1),add(y,i,1);
       if(x!=0)
            add(i,x,1);add(x,i,1);
   }
    memset(dis,0,sizeof dis);
    dfs(1,0);
    memset(vis,0,sizeof vis);
    ans=0;
    dfs(node,0);
    printf("%d",ans);
    system("pause"); 
    return 0;
}

/*
10 16
1 2
1 4
1 10
2 3
2 5
4 3
4 5
4 8
6 8
7 6
7 9
8 5
9 8
10 6
10 7
10 9

*/