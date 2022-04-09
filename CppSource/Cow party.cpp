#include<iostream>
#include<string.h>
using namespace std;
#define maxLen 9999
#define N 1001
/*爆栈错误
  需要进行优化，采用Spfa算法，或者进行dijkstra堆优化
*/

int n=0;
int m=0;
int visited[N];
int path[N][N];
int dis[N];

void dijkstra(int x);
bool isAllVisited();

int main(){
    int x;//party所在
    while(cin>>n>>m>>x){
        memset(visited,0,sizeof(visited));
        visited[x]=1;
        for(int i=1;i<=n;i++){
            dis[i]=maxLen;
            for(int j=1;j<=n;j++){
                path[i][j]=maxLen;
            }
        }//初始化path数组      
        dis[x]=0;

        int u,v,w;
        for(int i=1;i<=m;i++){
            cin>>u>>v>>w;
            path[u][v]=w;
        }

        dijkstra(x);//x到各点的最短距离==回家时的情况
        int dis1[n+1];
        memcpy(dis1,dis,(n+1)*sizeof(int));
        // swap(path);     
        int temp[n+1][n+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                swap(path[i][j],path[j][i]);
            }
        }

        memset(visited,0,sizeof(visited));
        for(int i=1;i<=n;i++)
            dis[i]=maxLen;
        dis[x]=0;
        dijkstra(x);
        int dis2[n+1];

        memcpy(dis2,dis,(n+1)*sizeof(int));

        int result=0;
        for(int i=1;i<=n;i++){
            result=max(result,dis1[i]+dis2[i]);
        }
        cout<<result<<endl;
    }

}

void dijkstra(int x){
    int next=x;
    for(int searchNum=1;searchNum<=n;searchNum++){
        for(int j=1;j<=n;j++){
            if(path[next][j]!=maxLen && visited[j]!=1){
                dis[j]=min(dis[j],dis[next]+path[next][j]);
            }
        }
        //寻找dis中未被标记中最小的，作为下一次出发点
        int minNum=maxLen;
        for(int j=1;j<=n;j++){
            if(visited[j]!=1 && minNum>dis[j]){
                minNum=dis[j];
                next=j;
            }
        }
        visited[next]=1;
        if(isAllVisited())
            break;        
    }

}

bool isAllVisited(){
    bool flag=1;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            flag=0;
            break;
        }
    }
    return flag;
}
// void swap(int path[][]){
//     int temp[n+1][n+1];
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             temp[j][i]=path[i][j];
//         }
//     }
//     memcpy(path,temp,sizeof(temp));
// }


