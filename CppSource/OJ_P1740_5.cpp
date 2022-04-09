#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll e[5500][5500],dis[5500],x[5500],y[5500];
int book[5500],n;
void init(){
	for(int i=1;i<=n;i++)    e[i][i]=0;
}
ll dist(int i,int j){
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
void Prim()
{
	int i,j,u,v;
	memset(book,0,sizeof(book));
	for(i=1;i<=n;i++)   dis[i]=e[1][i];
	book[1]=1;            //把1加入到树中
	ll mind,ans=0;
	for(i=1;i<=n-1;i++)
	{
    	mind=INF;u=-1;
    	for(j=1;j<=n;j++)
    	{
        	if(!book[j]&&mind>dis[j])
        	{
            	mind=dis[j];
            	u=j;
        	}
    	}
    	if(u==-1)    break;
    	ans=max(ans,dis[u]);
    	book[u]=1;
    	for(v=1;v<=n;v++)
    	{
        	if(!book[v]||e[u][v]<INF)
        	{
            	if(dis[v]>e[u][v])
                	dis[v]=e[u][v];
        	}
    	}
	}
	printf("%lld\n",ans);

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++)    
        	scanf("%lld %lld",&x[i],&y[i]);
    	init();
    	for(int i=1;i<=n;i++)
        	for(int j=i+1;j<=n;j++)
            	e[i][j]=e[j][i]=dist(i,j);
    	Prim();
        system("pause");
	}
	return 0;
}

