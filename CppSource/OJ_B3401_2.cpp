#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
#define MAX_N 2501
#define MAX_M 6201
#define INF 0x3f3f3f3f

int n,m,s,t;
int cnt=0;
int head[MAX_N],dis[MAX_N],vis[MAX_N];
typedef pair<int,int> pi;
priority_queue<pi> q;

struct edge{
    int to;
    int w;
    int next;
}edge[MAX_M<<2];

void add(int u,int v,int w){
    edge[++cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
}

void dij(int s){
    q.push(make_pair(dis[s],s));
    while (!q.empty())
    {
        int p=q.top().second;
        q.pop();
        if(vis[p])
            continue;
        vis[p]=1;
        for(int i=head[p];i>0;i=edge[i].next){//É¨Ãè³ö±ß
            int tto=edge[i].to; 
            if(dis[p]+edge[i].w<dis[tto]){
                dis[tto]=dis[p]+edge[i].w;
                q.push(make_pair(-dis[tto],tto));
            }
            //ËÉ³Ú
        }
    }
    return;
}

int main(){
    cin>>n>>m>>s>>t;
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    memset(dis,INF,sizeof(dis));
    dis[s]=0;
    memset(vis,0,sizeof(vis));

    dij(s);
    cout<<dis[t]<<endl;
    system("pause");
    return 0;
}

