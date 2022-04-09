#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

const int MAXN=1000005;
const int INF=0x3f3f3f3f;
const int mod=998244353;

using namespace std;

int fa[MAXN], a[MAXN];

int find(int x) {
	while(x!=fa[x])x=fa[x]=fa[fa[x]];
	return x;
}
int pow(int n) {
	int ans=1,base=2;
	for(int i=1;i<=n;++i) {
		ans=(ans*base)%mod;
	}
	return ans;
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
		fa[i]=i;
	}
	for(int i=1;i<=n;++i) {
		int u=find(i), v=find(a[i]);
		if(u!=v) fa[u]=v;
	}
	int cnt=0;
	for(int i=1;i<=n;++i) {
		if(fa[i]==i) cnt++;
	}
	printf("%d",pow(cnt)-1);
    system("pause");
	return 0;	
}
