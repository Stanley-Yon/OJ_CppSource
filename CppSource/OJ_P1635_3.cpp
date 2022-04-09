#include<bits/stdc++.h>
using namespace std;
#define MAX_N (int)1e4+5
typedef long long ll;

/**
 * @brief 
 * AC´úÂë
 */

struct YUE {
    ll t, b, h;
    bool operator<(const YUE &x) const {return b<x.b?1:0;}
}yue[MAX_N];

struct EAT{
    ll t,h;
    bool ch;
}eat[MAX_N];
ll dp[MAX_N],ans=0;
int n, T; 

int main() {
    cin>>n>>T;
    for(int i=1;i<=n;++i) 
        cin>>yue[i].t>>yue[i].b>>yue[i].h;
    sort(yue+1,yue+1+n);
    yue[n+1].t=0; 
    yue[n+1].b=(int)1e4+5; 
    yue[n+1].h=0;
    eat[0].ch=true;

    for(int i=1;i<=n;++i) {
        eat[i].h=eat[i-1].h+yue[i].h;
        eat[i].t=eat[i-1].t+yue[i].t;
        eat[i].ch=eat[i-1].ch && eat[i].t<=yue[i].b && eat[i].t<=T;
    }
    for(int i=n;i>=0;--i) {
        for(int j=T;j>=yue[i+1].t;--j) {
            dp[j]=max(dp[j], dp[j-yue[i+1].t]+yue[i+1].h);
        }
        if(eat[i].ch) {
            ans=max(ans, dp[min((ll)T, yue[i+1].b-1)-eat[i].t]+eat[i].h);
        }
    }
    cout<<ans<<endl;
    system("pause");
}
