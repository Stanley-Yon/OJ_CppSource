#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
#define MAX_M 1001
#define MAX_N 1001

int head[MAX_M],cnt,n,m;
queue<int> q;
int ru[MAX_N],ans[MAX_N],res;
/*
    head[i]表示与以i为起点的最后一条边的存储地址

    前向链星搜索时是从输入边的逆序开始的    
*/

struct Edge{
    int to;      //第i条边的终结点
    int next;   //与第i条边同起点的下一条边的存储地址
}edge[MAX_M];

void add(int u,int v){
    edge[++cnt].to=v;
    edge[cnt].next=head[u]; 
    head[u]=cnt;
}

void bfs(){
    for(int i=1;i<=n;i++){
        if(!ru[i]) {
            q.push(i);
        }
    }
    while(!q.empty()){
        int p=q.front(); q.pop();
        for(int i=head[p];i>0;i=edge[i].next)
        {
            int tto=edge[i].to;
            ans[tto]=max(ans[tto],ans[p]+1);
            res=max(res,ans[tto]);
            ru[tto]--;
            if(!ru[tto])
                q.push(tto);
        }  

    } 


}

int main(){
    while(cin>>n>>m){
        cnt=0,res=0;
        memset(head,0,sizeof(head)), memset(ru,0,sizeof(ru)); 
        for(int i=1;i<=n;i++)
            ans[i]=1;
        int u,v;
        for(int i=1;i<=m;i++){
            cin>>u>>v;
            add(u,v);
            ru[v]++;
        }
        bfs();
        // for(int i=1;i<=n;i++)
        //     res=max(res,ans[i]);
        cout<<res<<endl;
    }
    return 0;
}

/*
解析：
    寻求最长链的模板题：
        输入时注意将其父节点和子节点进行前向星连边，边权都设置为1
        随机找一个点，也就是根节点，然后跑一遍DFS，寻求最大值，并且记录下最大值的标号，
        然后再从此标号跑一遍DFS,最后得到一个最大值,即为所求.

*/

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

6

*/