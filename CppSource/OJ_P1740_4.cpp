#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
#define MAX_N  5100
#define INF 0x3f3f3f3f3f3f3f3f   //long long  需要非常大
int T,n;
struct NODE{
    int x,y;
}node[MAX_N];
long long g[MAX_N][MAX_N];
long long maxl=0;
bool vis[MAX_N];
long long dis[MAX_N];     //到达结点i的最短距离

long long getDis(NODE e1,NODE e2){
    return (e1.x-e2.x)*(e1.x-e2.x)+(e1.y-e2.y)*(e1.y-e2.y);
}

void prim(){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){//节点0开始
       dis[i]=g[0][i];
    }
    vis[0]=1;
    for(int i=1;i<n;i++){   //除0之外的所有点
        int minNode=-1;
        long long minl=INF;
        for(int j=0;j<n;j++){   //目的结点未被访问
            if(!vis[j] && dis[j]<minl){
                minl=dis[j];
                minNode=j;
            }
        }
        vis[minNode]=1;
        maxl=max(maxl,dis[minNode]);
        for(int j=0;j<n;j++)
            if(!vis[j] || g[minNode][j]<INF)         //  !g[minNode][j]
                dis[j]=min(dis[j],g[minNode][j]);
    }
}

int main(){
    cin>>T;
    while(T--){
        maxl=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>node[i].x>>node[i].y;
            for(int j=i-1;j>=0;j--){
                g[i][j]=g[j][i]=getDis(node[i],node[j]);
            }
        }
        prim();
        cout<<maxl<<endl;
        system("pause");

    }

}