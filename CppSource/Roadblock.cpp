#include<iostream>
#include<set>
#include<string.h>
using namespace std;
#define MAX_N 255
#define MAX_M 250010
#define INF 0X3f3f3f
typedef pair<int,int> pi;

int N,M;
int graph[MAX_N][MAX_N];
int dis1[MAX_N],dis2[MAX_N],dis3[MAX_N];

set<pi> setH;  // <dis[s],s>  set集合从小到大排序

//Dijkstra算法使用set集合(****有优势****)
void dij(int dis[],int s){
    dis[s]=0;
    setH.insert(make_pair(dis[s],s));
    while(!setH.empty()){
        int w=setH.begin()->first;
        int now=setH.begin()->second;
        setH.erase(make_pair(w,now));

        for(int j=1;j<=N;j++){
            if(dis[now]+graph[now][j]<dis[j]){
                setH.erase(make_pair(dis[j],j));
                dis[j]=dis[now]+graph[now][j];
                setH.insert(make_pair(dis[j],j));
            }
        }
    }
    return;
}

int main(){
    memset(graph,INF,sizeof(graph));
    memset(dis1,INF,sizeof(dis1));
    memset(dis2,INF,sizeof(dis2));
    // memset(dis3,INF,sizeof(dis3));
    cin>>N>>M;
    int u,v,w;
    for(int i=1;i<=M;i++){
        cin>>u>>v>>w;
        graph[u][v]=w;
        graph[v][u]=w;
    }
    
    //1---->n
    dij(dis1,1);
    //n---->1
    dij(dis2,N);

    int res=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(dis1[i]+graph[i][j]+dis2[j]==dis1[N]){
                graph[i][j]*=2,graph[j][i]*=2;
                memset(dis3,INF,sizeof(dis3));
                dij(dis3,1);
                graph[i][j]/=2,graph[j][i]/=2;
                res=max(res,dis3[N]-dis1[N]);
            }
        }
    }
    cout<<res<<endl;
    system("pause");
    return 0;
}
/*
寻找开始的最短路径：将其边扩充两倍走之后，再次使用Dijkstra

dis1[i] + graph[i][j] + dis2[j]   是否等于  dis1[N]

*/