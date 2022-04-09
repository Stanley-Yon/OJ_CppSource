#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define Max 1001

int n,m,s,t;
int node[2500][2500];
int dis[2500];
int visited[2500];

void dijkstra(int dis[],int visited[]);
int isAllSearch(int visited[]);
int isVisited(int visited[],int j);

int main(){
        cin>>n>>m>>s>>t;//n个点，m条边，s->t的最短路径
        memset(node,0,sizeof(node));
        memset(visited,0,sizeof(visited));
        int u,v,length;
        for(int i=1;i<=m;i++){
            cin>>u>>v>>length;
            node[u][v]=length;
            node[v][u]=length;
        }
        for(int i=1;i<=n;i++){
            dis[i]=Max;
        }
        dis[s]=0;
        visited[s]=1;
        dijkstra(dis,visited);
        cout<<dis[t]<<endl;
        return 0;
}

void dijkstra(int dis[],int visited[]){
    int searchNode=s;
    while(!isAllSearch(visited)){     
        for(int j=1;j<=n;j++){
            if(node[searchNode][j]!=0 && !isVisited(visited,j)){
                dis[j]=min(dis[j],dis[searchNode]+node[searchNode][j]);
            }
        }

        int minLen=Max;
        int nextNode=0;
        for(int i=1;i<=n;i++){
            if(minLen>dis[i] &&visited[i]!=1){
                nextNode=i;
                minLen=dis[i];
            }
              
        }
        visited[nextNode]=1;
        searchNode=nextNode;
    }
}

int isAllSearch(int visited[]){
    int flag=1;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            flag=0;
            break;
        }
    }
    return flag;
}

int isVisited(int visited[],int j){
    int flag=0;
    if(visited[j]==1)
        flag=1;
    return flag;
}