#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
#define MAX_N 5005
#define INF 0x3f3f3f3f3f3f

int T,n,cnt;
long long maxl;
long long g[MAX_N][MAX_N];
long long dis[MAX_N];
struct NODE{
    long long x,y;
}node[MAX_N];

long long getDis(NODE n1,NODE n2){
    return (n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y);
}

void prim(){
    for(int i=0;i<n;i++)
        dis[i]=g[0][i];
    dis[0]=INF;    
    for(int i=1;i<n;i++){
        int minN=0;
        for(int i=0;i<n;i++){
            if(dis[i]<=dis[minN] && dis[i]!=0)
                minN=i;
        }
        int to=0;
        for(int i=0;i<n;i++){
            if(dis[i]==INF && dis[i]!=0 && g[minN][to]>g[minN][i])   //寻找该点的父亲 
                to=i;
        }
        dis[minN]=INF;// 收入该点
        maxl=max(maxl,g[minN][to]);
        for(int i=0;i<n;i++){
            if(dis[i]!=INF && dis[i]!=0)
                dis[i]=min(dis[i],g[minN][i]);
        }
    }

}

int main(){
    cin>>T;
    while (T--)
    {
        maxl=0;
        memset(dis,0,sizeof(dis));
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
    return 0;
}


// long long getDis(NODE n1,NODE n2){
//     return pow((n1.x-n2.x),2)+pow((n1.y-n2.y),2);
// }
void prim1(){
    dis[0]=INF;//dis=INF的时候说明该点已经被收入连通图，这里先把 0节点收入 
	for(int i=1;i<n;i++)//初始化一下dist 
		dis[i]=g[0][i];
	for(int i=1;i<=n;i++)//每次循环都会收入一个点，循环n次全部收入 
	{
		int min1=0;
		for(int i=2;i<=n;i++)//找一下没有被收录的点里面最小的dist（因为被收录的店已经是INF了） ，也可以用最小堆维护来优化 
			if(dis[i]<dis[min1])
				min1=i;
		int from=1;
		for(int i=1;i<=n;i++)//找一下这个点被收入的时候是由哪个点为父亲
			if(dis[i]==INF&&g[from][min1]>g[i][min1])
				from=i;
		dis[min1]=INF;//表示这个点已经被收入 
		maxl=max(maxl,g[from][min1]);//更新ans 
		for(int i=1;i<=n;i++)//在没有被收入的点里面更新被影响了dist的点 
		{
			if(dis[i]!=INF)
				dis[i]=min(g[min1][i],dis[i]);
		}
    }
}