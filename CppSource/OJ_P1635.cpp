#include<iostream>
#include<algorithm>
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

using namespace std;
typedef long long ll;

const int MAXN=1e4+5;

struct C {
    ll t, b, h;
    bool operator<(const C & x) const {return b<x.b;}
}c[MAXN];

ll dp[MAXN], pret[MAXN], preh[MAXN];
bool check[MAXN];
int main() {
    int n, T; cin>>n>>T;
    for(int i=1;i<=n;++i) cin>>c[i].t>>c[i].b>>c[i].h;
    sort(c+1, c+1+n);

    c[n+1].t=0; c[n+1].b=10000000; c[n+1].h=0;
    check[0]=true;
    for(int i=1;i<=n;++i) {
        preh[i]=preh[i-1]+c[i].h;
        pret[i]=pret[i-1]+c[i].t;
        check[i]=check[i-1] && pret[i]<=c[i].b && pret[i]<=T;
    }
    ll ans=0;
    for(int i=n;i>=0;--i) {
        for(int j=T;j>=c[i+1].t;--j) {
            dp[j]=max(dp[j], dp[j-c[i+1].t]+c[i+1].h);
        }
        if(check[i]) {
            ans=max(ans, dp[min((ll)T, c[i+1].b-1ll)-pret[i]]+preh[i]);
        }
    }
    cout<<ans<<endl;
    system("pause");
}
