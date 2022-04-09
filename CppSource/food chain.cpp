#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
#define MAX_N 1001

int head[MAX_N],cnt,n,m;
queue<int> q;
int ru[MAX_N],ans[MAX_N],visited[MAX_N];
/*
    head[i]表示与i同起点的下一条边的存储地址
*/

struct Edge{
    int to;      //第i条边的终结点
    int next;   //与第i条边同起点的下一条边的存储地址
}edge[MAX_N];

void add(int u,int v){
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}

void bfs(){
    for(int i=1;i<=n;i++){
        if(!ru[i]) {
            q.push(i),ans[i]=1;
        }
    }
    while(!q.empty()){
        int p=q.front(); q.pop();
        visited[p]=0;
        for(int i=head[p];i>0;i=edge[i].next){
            int tto=edge[i].to;
            ans[tto]+=ans[p];
            if(!visited[tto]){
                q.push(tto);
                visited[tto]=1;
            }          
        }  
        if(head[p])
            ans[p]=0;
    }  
}

int main(){
    while(cin>>n>>m){
        cnt=0;
        memset(head,0,sizeof(head)),      memset(ru,0,sizeof(ru)); 
        memset(visited,0,sizeof(visited)),memset(ans,0,sizeof(ans));

        int u,v;
        for(int i=1;i<=m;i++){
            cin>>u>>v;
            add(u,v);
            ru[v]++;
        }

        bfs();
        int res=0;
        for(int i=1;i<=n;i++)
        if(!head[i] && ru[i])
            res+=ans[i];
        cout<<res<<endl;
    }
    return 0;
}


/*

10 16
1 2
1 4
1 10
2 3
2 5
4 3
4 5
4 8
6 8
7 6
7 9
8 5
9 8
10 6
10 7
10 9

*/