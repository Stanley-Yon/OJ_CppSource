#include<bits/stdc++.h>
using namespace std;
#define MAX_N (int)1e4+1
#define INF 2147483647
typedef long long ll;
int n,m,s;
ll g[MAX_N][MAX_N],dis[MAX_N];
int vis[MAX_N];

/**
 * @brief 
 * 点s到其他点的最短距离
 */

void dij()
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        dis[i]=g[s][i];             //dis初始化为起点到其他所有点的边
    dis[s]=0;
    vis[s]=1;

    for(int k=2;k<=n;k++)
    {
        ll minl=INF;
        int v;
        for(int i=1;i<=n;i++){
            if(!vis[i] && dis[i]<minl ){
                minl=dis[i];
                v=i;
            }
        }
        vis[v]=1;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dis[i]=min(dis[i],dis[v]+g[v][i]);
            }
        }

    }

}

int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        g[i][j]=INF;
    int u,v;
    ll w;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        g[u][v]=min(g[u][v],w);
    }
    dij();
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    cout<<endl;
    system("pause");
    return 0;
}


/**
 * @brief 
 *      Dijkstra
 * 
 * 有重复的点->点的边,选择最小的记录下来
5 15 5
2 5 181
1 5 98
4 2 49
3 2 262
4 3 26
2 4 192
5 1 221
2 2 254
4 4 233
1 5 44
5 4 67
4 2 214
1 1 47
1 1 118
5 4 3


221 52 29 3 0 
 */