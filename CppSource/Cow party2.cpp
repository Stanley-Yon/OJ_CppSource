#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
#define MAX_N 1001
#define MAX_M 100001
#define INF 0x3f3f
// typedef make_pair mp;
// typedef pair<int ,int> pi;

int n,m,x;
int u[MAX_M],v[MAX_M],w[MAX_M];
int head[MAX_N];
int cnt;
int dis[MAX_N],vis[MAX_N];

struct edge{
    int to;
    int w;
    int next;
}edge[MAX_M];

void add(int u,int v,int w){
    edge[++cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
}

void dij(int x){
    priority_queue<pair<int ,int>> q;
    q.push(make_pair(0,x));
    dis[x] = 0;
	while (!q.empty()) {
		int p=q.top().second;
		q.pop();
		if (vis[p])
            continue;
		vis[p] = 1;
		for (int i=head[p]; i; i=edge[i].next) {
			int v=edge[i].to;
			if (dis[v]>dis[p]+edge[i].w) {
				dis[v]=dis[p]+edge[i].w;
				q.push(make_pair(-dis[v], v));//-dis[v] ************
			}
		}
	}

}

int main(){
    cin>>n>>m>>x;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        add(u[i],v[i],w[i]);
    }
    memset(vis,0,sizeof(vis));
    memset(dis,INF,sizeof(dis));

    dij(x);
    int res[n+1];       
    for(int i=1;i<=n;i++)
        res[i]=dis[i];      
    cnt=0;
    memset(head,0,sizeof(head));
    for(int i=1;i<=m;i++)
        add(v[i],u[i],w[i]);
    
    memset(vis,0,sizeof(vis));
    memset(dis,INF,sizeof(dis));
    
    dij(x);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,res[i]+dis[i]);
    printf("%d\n",ans);
    system("pause");
    return 0;
}