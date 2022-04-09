#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f   //INF 0x3f3f3f3f3f3f3f3f  需要非常大
#define MAX_N 5500
typedef long long ll;
/*

	过了！！！！QAQ

*/
ll g[MAX_N][MAX_N],dis[MAX_N],x[MAX_N],y[MAX_N];
int vis[MAX_N],n;

ll getdis(int i,int j){
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
void prim(){
	int i,j,u,v;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++)   
        dis[i]=g[1][i];
	vis[1]=1;        
	ll minl,ans=0;
	for(i=1;i<=n-1;i++)
	{
    	minl=INF;
        u=-1;
    	for(j=1;j<=n;j++){
        	if(!vis[j] && dis[j]<minl){
            	minl=dis[j];
            	u=j;
        	}
    	}
    	if(u==-1)    break;
    	ans=max(ans,dis[u]);
    	vis[u]=1;
    	for(v=1;v<=n;v++){
        	if(!vis[v] || g[u][v]<INF )
                dis[v]=min(dis[v],g[u][v]);
    	}
	}
	printf("%lld\n",ans);
}
int main()
{
	int T;
	scanf("%lld",&T);
	while(T--)
	{
    	scanf("%lld",&n);
    	for(int i=1;i<=n;i++){
			scanf("%lld %lld",&x[i],&y[i]);
		}    
		for(int i=1; i<=n;i++)
            for(int j=i+1; j<=n; j++)	
				g[i][j]=g[j][i]=getdis(i,j);
    	prim();
        system("pause");
	}
	return 0;
}
