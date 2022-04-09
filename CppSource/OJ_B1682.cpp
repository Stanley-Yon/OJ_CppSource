/*
    prim算法  
    此算法可以称为“加点法”，每次迭代选择代价最小的边对应的点，加入到最小生成树中。算法从某一个顶点s开始，逐渐长大覆盖整个连通网的所有顶点。

    图的所有顶点集合为VV；初始令集合u={s},v=V?uu={s},v=V?u;
    在两个集合u,vu,v能够组成的边中，选择一条代价最小的边(u0,v0)(u0,v0)，加入到最小生成树中，并把v0v0并入到集合u中。
    重复上述步骤，直到最小生成树有n-1条边或者n个顶点为止。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
int dis[5000+10][5000+10],minn[6000];       //dis用来存距离，minn求答案值
bool vis[6000];         //记录访问情况
ll sum;             //用来累加

int main(){
	int n,m;
	scanf("%d%d",&n,&m);

    memset(dis,INF,sizeof(dis));//初始化
    int x,y,z;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        dis[x][y]=min(dis[x][y],z);//双向图存图（邻键表）
        dis[y][x]=min(dis[y][x],z);
    }

    memset(vis,false,sizeof(vis));//继续初始化
    memset(minn,INF,sizeof(minn));
    minn[1]=0;


    for(int i=1;i<=n;i++){          //Prim模板开始
        int k=0;
        for(int j=1;j<=n;j++)
            if(!vis[j]&& minn[j]<minn[k] )//找点
                k=j;
        vis[k]=true;            //标记已访问
        for(int j=1;j<=n;j++)
            if(!vis[j])
                minn[j]=min(minn[j],dis[k][j]);        //更新最小值
    }

    for(int i=1;i<=n;i++)
        sum=max((ll)minn[i],sum);       //找最大值
    printf("%lld",sum);
	return 0;
}