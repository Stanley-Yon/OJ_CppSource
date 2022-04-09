#include<bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') f |= ch == '-' ? 1 : -1, ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}
inline void print(int x){
	char P[105];int w=0;if(x==0){putchar('0');return;}
	if(x<0) putchar('-'),x=-x;
	while(x) P[++w]=x%10+'0',x/=10;
	for(int i=w; i>=1; i--) putchar(P[i]);
}


const int N = 1e5;
struct node {
	int dis, next, val;
} edge[N + 1];
int siz, head[N + 1];
inline void add(int from, int dis,int val) {
	edge[++siz].dis = dis;
	edge[siz].val = val;
	edge[siz].next = head[from];
	head[from] = siz;
}

int n, m, x, ans, an[N + 1];
int vis[N + 1], dis[N + 1];
inline void SPFA(int s) {
	queue<int> q;
	memset(dis, 0x3f, sizeof dis); dis[s] = 0;
	memset(vis, 0, sizeof vis); 
	vis[s] = 1; q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop(); vis[u] = 0;
		for (int i = head[u]; i; i = edge[i].next) {
			int to = edge[i].dis;
			if (dis[u] + edge[i].val < dis[to]) {
				dis[to] = dis[u] + edge[i].val;
				if (!vis[to]) {
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}
}
int main() {
	n = read(), m = read(), x = read();
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read(), w = read();
		add(u, v, w);
	}
	SPFA(x);
	for (int i = 1; i <= n; i++) an[i] = dis[i];

	for (int i = 1; i <= n; i++) {
		SPFA(i);
		int a = dis[x];
		ans = max(ans, a + an[i]);
	}
	print(ans);
    system("pause");
	return 0;
}