#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;//  ���---->int �ıߵľ���int
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
	priority_queue <Node> Q;    //���ȶ���
	Q.push(Node(st, 0));        //Ԫ�ز�������е���
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
	for(int i=1; i<=n; i++) g[i].clear();//vector.clear�����������ǽ�size��գ�capacity����

	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		g[x].push_back(make_pair(y, z));//push_back()�������÷�:
                                                //������һ���µ�Ԫ�ؼӵ�vector������棬λ��Ϊ��ǰ���һ��Ԫ�ص���һ��Ԫ��
		//g[y].push_back(make_pair(x, z));
	}
	dijkstra(st);
	for(int i=1; i<=n; i++)
		printf("%d%s", dis[i], " \n"[i==n]);

}



/*
dijkstra�㷨���̣�
    1��������ľ�����Ϊ0,������Ϊ�������
    2�����δ��ǵģ�������С�ĵ㣬Ϊu
    3������u��ÿ���ڱ�v��dis[v]=min(dis[v],dis[u]+w(u,v))
    4���ض�ִ��n-1��
    ʱ�临�Ӷ�O(n^2)

���Ż�(���ٽ���)��









*/