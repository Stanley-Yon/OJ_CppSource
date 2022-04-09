#include<bits/stdc++.h>
using namespace std;
#define MAX_N 2002
#define MAX_M (int)1e4+2
int n,m,maxl=0;
int f[MAX_N];

/**
 * 克里斯凯尔算法
 * 
 */

struct  EDGE
{
    int u,v,w;
    bool operator< (const EDGE &e) {return w<e.w;}
}edge[MAX_M];

int find(int x){
    while(f[x]!=x)
        x=f[x];
    return x;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    sort(edge,edge+m);
    // for(int i=0;i<m;i++)
    //     cout<<edge[i].w<<endl;

    for(int i=0;i<=n;i++)
        f[i]=i;
    int cnt=0,p1,p2;
    for(int i=0;i<m;i++){
        if(cnt==n-1)
            break;
        p1=find(edge[i].u);
        p2=find(edge[i].v);
        if(p1!=p2){         //加边
            f[p2]=p1;
            ++cnt;
            maxl=max(maxl,edge[i].w);           
        }
    }
    cout<<maxl<<endl;
    system("pause");
    return 0;
}