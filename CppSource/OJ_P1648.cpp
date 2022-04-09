#include<iostream>
using namespace std;
#define MOD  998244353

const int MAX_N=1e6+1;
int f[MAX_N],a[MAX_N];
int cnt;

int find(int x){
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=i;
    }

    for(int i=1;i<=n;i++){
        int pre1=find(i);
        int pre2=find(a[i]);
        if(pre1!=pre2)  
            f[pre1]=pre2;
    }
    for(int i=1;i<=n;i++)
    if(f[i]==i)
        cnt++;
    long long res=1;
    int i=1;
    while(i<=cnt){
        res=(res*2)%MOD;
        i++;
    }
    cout<<res-1<<endl;
    system("pause");
    return 0;
}