#include<bits/stdc++.h>
using namespace std;
int m,n,s,p=0,head[2005],d1[2005],d2[2005];
bool vis[2005];
priority_queue< pair<int, int> > q;
struct la{
	int to,nxt,val;
}e[200050];
inline int read(){
	int w=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		w=(w<<1)+(w<<3)+(ch-48);
		ch=getchar();
	}
	return w*f;
}
void write(int x){
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void add(int from,int w,int v){
	e[++p].to=w;
	e[p].val=v;
	e[p].nxt=head[from];
	head[from]=p;
}
void dij(int s,int *dis){
	memset(vis,false,sizeof(vis));
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int j=head[x];j;j=e[j].nxt){
			int u=e[j].to;
			if(dis[x]+e[j].val<dis[u]){
				dis[u]=dis[x]+e[j].val;
				q.push(make_pair(-dis[u],u));
			}
		}
	}
}
int main(){
	n=read();m=read();s=read();
	for(int i=1;i<=m;i++){
		int a,b,c;
		a=read();b=read();c=read();
		if(a==b) continue;
		add(a,b,c);
		add(b+n,a+n,c);
	}
	int ans=0;
	memset(d1,0x3f,sizeof(d1));
	memset(d2,0x3f,sizeof(d2));
	dij(s,d1);
    dij(s+n,d2);
    for(int i=1;i<=n;i++){
    	ans=max(ans,d1[i]+d2[i+n]);
	}
    write(ans);
    system("pause");
	return 0;
}