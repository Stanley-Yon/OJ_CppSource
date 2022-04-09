#include<bits/stdc++.h>
using namespace std;
#define MAX_N 1002
#define MAX_T 10000
typedef long long ll;
int n,T;
ll ans=0;
ll dp[MAX_N];

struct YUE
{
    ll t,b,h;
}yue[MAX_N];

struct EAT{ //必须吃
    ll t;      //花费时间
    ll h;      //获得happiness
}eat[MAX_N];

bool cmp1(YUE y1,YUE y2){
    return y1.b<y2.b?1:0;
}
bool cmp2(YUE y1,YUE y2){
    return y1.h>y2.h?1:0;
}

int main(){
    cin>>n>>T;
    for(int i=1;i<=n;i++)
        cin>>yue[i].t>>yue[i].b>>yue[i].h;
    sort(yue+1,yue+n+1,cmp1);
    for(int i=0;i<=T;i++){
        int t=0,h=0;
        for(int j=1;j<=n;j++){
            if(yue[j].b<=i){
                t+=yue[j].t;
                h+=yue[j].h;
            }
            else 
                break;
        }
        eat[i].t=t;
        eat[i].h=h;
    }

    // for(int i=0;i<=T;i++){
    //     cout<<eat[i].t<<" "<<eat[i].h<<endl;
    // }

    sort(yue+1,yue+n+1,cmp2);    
    for(int i=n;i>=0;i--){ 
        for(int j=T;j>=yue[i+1].t;j--){
           dp[j]=max(dp[j],dp[j-yue[i+1].t]+yue[i+1].h);
            if(eat[i].t<yue[i].b && eat[i].t<=T)
                ans=max(ans,dp[min(ll(T),yue[i+1].b-1ll)-eat[i].t]+eat[i].h);

        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}



/**
3 10
2 5 2
7 9 4
1 8 3


必须吃  (月饼按过期时间排序)

选择吃   (按照快乐值降序排列)


dp[i][j]: 第i个物体放入容量为j的背包内

 */

