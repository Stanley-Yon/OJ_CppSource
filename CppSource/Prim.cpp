#include<bits/stdc++.h>
using namespace std;
#define MAX_N 2002
#define MAX_M (int)1e4+1
#define INF 0x3f3f3f3f
int n,m,ans;
int vis[MAX_N],dis[MAX_N];
int g[MAX_N][MAX_N];

void prim()
{
    memset(vis,0,sizeof(vis));
    memset(dis,INF,sizeof(dis));
    dis[1]=0;

    for(int k=1;k<=n;k++)
    {   
        int to=0;
        for(int i=1;i<=n;i++){
            if(!vis[i] && dis[i]<dis[to]){
                to=i;
            }
        }
        vis[to]=1;
        for(int i=1;i<=n;i++){
            if(!vis[i] && dis[i]>g[to][i] ){
                dis[i]=g[to][i];
            }
        }


    }

}

int main()
{   
    cin>>n>>m;
    memset(g,INF,sizeof(g));
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        g[u][v]=min(g[u][v],w);
        g[v][u]=min(w,g[v][u]);
    }
    prim();

    for(int i=1;i<=n;i++)
        ans=max(ans,dis[i]);
    cout<<ans<<endl;

    system("pause");
}