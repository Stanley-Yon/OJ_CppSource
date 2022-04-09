#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int ,int> pii;
priority_queue<pii> q;

const int MAX_N=1e3+1;  //注意大小
const int MAX_M=1e5+1;
int dis[MAX_N];
int vis[MAX_N];
int u[MAX_M], v[MAX_M], w[MAX_M];
int head[MAX_N];
int cnt=0,n,m,x;

/*
    edge[i].next表示与第i条边同起点的下一条边的存储位置
*/
struct Edge{
    int next;
    int to;
    int w;
}edge[MAX_M];

void add(int u,int v,int w){
    edge[++ cnt].next = head[u];
    edge[cnt].w = w;
    edge[cnt].to = v;
    head[u] = cnt;
}

void dijkstra(int s){
    // for (int i = 1; i <= n; i++) 
    //     dis[i] = INF;  //无穷大
	q.push(make_pair(0, s));
	dis[s] = 0;
	while (q.size()) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = edge[i].next) {
			int v = edge[i].to;
			if (dis[v] > dis[u] + edge[i].w) {
				dis[v] = dis[u] + edge[i].w;
				q.push(make_pair(-dis[v], v));
			}
		}
	}
}


int main(){
    cin>> n >> m >> x ;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        add(u[i],v[i],w[i]);
    }
    memset(dis,INF,sizeof(dis));
    memset(vis,0,sizeof(vis));
    // memset(head, 0, sizeof(head));

    dijkstra(x);
    int res1[n+1];
    for(int i=1;i<=n;i++){
        res1[i]=dis[i];
    }

    memset(dis,INF,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(head, 0, sizeof(head));
    cnt=0;

    //方向倒过来
    for (int i = 1; i <= m; i ++ )
        add(v[i], u[i], w[i]);
    dijkstra(x);

    int summ=0;
    for(int i=1;i<=n;i++){
        dis[i]+=res1[i];
        summ=max(summ,dis[i]);
    }
    cout<<summ<<endl;
    system("pause");
    return 0;

}