#include<bits/stdc++.h>
using namespace std;
#define MAX_N (int)3e5+5
#define MAX_M (int)1e6+6
int T,cnt,n,m;
int f[MAX_N];
int node[MAX_N],edge[MAX_M];

int find(int x){
    if(f[x]==x)
        return x;
    return f[x]=find(f[x]);
}

int main(){
    int t=1;
    cin>>T;
    while(t<=T)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            f[i]=i;
            node[i]=1;
        }
        memset(edge,0,sizeof edge);      
        cnt=0;  
        int f1,f2,x,y;
        for(int i=0;i<m;i++){
            cin>>f1>>f2;
            x=find(f1);
            y=find(f2);
            if(x==y)
                edge[x]++;
            else{
                f[y]=x;
                edge[x]+=edge[y];
                edge[x]++;
                node[x]+=node[y];
            }
        }
        for(int i=1;i<=n;i++){
            if(f[i]!=i)
                continue;
            if(edge[i]-node[i]>=0)
                cnt+=edge[i]-node[i];
        }
        cout<<"Case #"<<t<<": "<<cnt<<endl;
        t++;
    }


    system("pause");
    return 0;
}