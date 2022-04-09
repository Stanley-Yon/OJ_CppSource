#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 5050;

int fa[maxn+10];
void init(int n){for(int i = 1; i <= n; i++) fa[i]=i;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x, int y){x=find(x);y=find(y);if(x!=y)fa[x]=y;}
int count(int n){int cnt=0; for(int i = 1; i <= n; i++)if(fa[i]==i)cnt++;return cnt;}

int n;
struct node{LL x, y; }a[maxn];
LL d[maxn][maxn];
bool cmp(node x, node y){return x.x!=y.x ?x.x<y.x :x.y<y.y;}
LL getd(node x, node y){return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);}
bool check(LL t){
    init(n);
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(t>=d[i][j]){
                if(find(i)!=find(j)){
                    cnt++;
                    if(cnt==n)break;
                    merge(i,j);
                }
            }
        }
        if(cnt==n)break;
    }
    return cnt==n;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;  cin>>T;
    while(T--){
        cin>>n;    
        for(int i = 1; i <= n; i++)
            cin>>a[i].x>>a[i].y;
        
        for(int i = 1; i <= n; i++)
            for(int j = i+1; j <= n; j++)
                d[i][j] = getd(a[i],a[j]);
        
        //sort(a+1,a+n+1,cmp);
        LL l = 0, r = 1e15+10;
        while(l < r){
            LL mid = (l+r)/2;
            if(check(mid)){
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        cout<<r<<endl;
        system("pause");
    }
    return 0;
}
