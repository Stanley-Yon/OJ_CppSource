#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3 + 10, M = 1e5 + 10;

int n, m, s, sum;
int ans[N];
int head[N], cnt;
int u[M], v[M], w[M];

//nxt  , to  目标结点, w  距离;  
struct Edge{
    int nxt, to, w;   
}edges[M];

void add(int u, int v, int w){
    edges[++ cnt].nxt = head[u];
    edges[cnt].w = w;
    edges[cnt].to = v;
    head[u] = cnt;
}

int dis[N], vis[N];

void dijkstra(int s) {
	for (int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f;  //无穷大
	priority_queue< pair<int, int> > q;
	q.push(make_pair(0, s));
	dis[s] = 0;
	while (q.size()) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = edges[i].nxt) {
			int v = edges[i].to;
			if (dis[v] > dis[u] + edges[i].w) {
				dis[v] = dis[u] + edges[i].w;
				q.push(make_pair(-dis[v], v));
			}
		}
	}
}

int main(){
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i ++ ){
        cin >> u[i] >> v[i] >> w[i];
        add(u[i], v[i], w[i]);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i ++ )
        ans[i] = dis[i];
    cnt = 0;
    memset(dis, 0, sizeof dis);
    memset(head, 0, sizeof head);
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= m; i ++ )
        add(v[i], u[i], w[i]);
    dijkstra(s);
    for (int i = 1; i <= n; i ++ ){
        ans[i] += dis[i];
        sum = max(sum, ans[i]);
    }
    cout << sum << endl;
    system("pasue");
    return 0;
}