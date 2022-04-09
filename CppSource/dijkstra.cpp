#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;//  结点---->int 的边的距离int
const int maxn = 1e5 + 10;  // maxn=100000+10
const ll inf = (ll)1e16;        // INF=10^16

int n, m;
bool vis[maxn];
ll dis[maxn];
vector <pii> g[maxn];

struct Node{
	int id; ll d;
	Node() {}
	Node(int id, ll d):id(id),d(d){}
	bool operator < (const Node &A) const {
		return d > A.d;
	}
};

void dijkstra(int st){
	for(int i=1; i<=n; i++){
		vis[i] = 0;
		dis[i] = inf;
	}

	dis[st] = 0;
	priority_queue <Node> Q;    //优先队列
	Q.push(Node(st, 0));        //元素插入进队列当中
	Node nd;

	while(!Q.empty()){
		nd = Q.top(); Q.pop();
		if(vis[nd.id]) continue;
		vis[nd.id] = true;
		for(int i=0; i<g[nd.id].size(); i++){
			int j = g[nd.id][i].first;
			int k = g[nd.id][i].second;
			if(nd.d + k < dis[j] && !vis[j]){
				dis[j] = nd.d + k;
				Q.push(Node(j, dis[j]));
			}
		}
	}
}

int main(){
	int x, y, z, st, ed, cas = 0;
	scanf("%d%d%d", &n, &m, &st);
	for(int i=1; i<=n; i++) g[i].clear();//vector.clear的真正作用是将size清空，capacity不变

	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		g[x].push_back(make_pair(y, z));//push_back()函数的用法:
                                                //函数将一个新的元素加到vector的最后面，位置为当前最后一个元素的下一个元素
		//g[y].push_back(make_pair(x, z));
	}
	dijkstra(st);
	for(int i=1; i<=n; i++)
		printf("%d%s", dis[i], " \n"[i==n]);

}



/*
dijkstra算法过程：
    1、出发点的距离设为0,其它点为正无穷大
    2、求出未标记的，距离最小的点，为u
    3、更新u的每条邻边v，dis[v]=min(dis[v],dis[u]+w(u,v))
    4、重读执行n-1次
    时间复杂度O(n^2)

堆优化(加速进程)：









*/