/*
    炼丹术
*/
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAX_N 5000
#define MAX_EDGE MAX_N*(MAX_N-1)/2

/******************************/
//超时
//尝试使用二分并查集

int T,n;
int x[MAX_N],y[MAX_N],f[MAX_N];
long long maxl;
struct Edge
{
    int u,v;
    long long w;
}edge[MAX_EDGE];

long long getDis(int x1,int y1,int x2,int y2){
    return pow(x1-x2,2)+pow(y1-y2,2);
}
bool cmp(Edge e1,Edge e2){
    return e1.w<e2.w;
}
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
bool isSame(int i,int j){
    return find(i)==find(j);
}

int main(){
    cin>>T;
    while (T--)
    {
        maxl=0;
        int cnt=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
            for(int j=i-1;j>=0;j--){
                edge[cnt].u=i;
                edge[cnt].v=j;
                edge[cnt++].w=getDis(x[i],y[i],x[j],y[j]);
            }
            
        }
        sort(edge,edge+cnt,cmp);
        for(int i=0;i<n;i++)
            f[i]=i;
        int end=0;
        for(int i=0;i<cnt;i++){
            if(! isSame(edge[i].u,edge[i].v)){
                int pre1=find(edge[i].u);
                int pre2=find(edge[i].v);
                f[pre1]=pre2;
                end++;
                maxl=max(maxl,edge[i].w);
            }
            if(end==n-1)
                break;
        }
        cout<<maxl<<endl;
        system("pause");
    }
    return 0;
}

/*

2
3
0 0
1 1
0 1
5
1 1
4 5
1 4
2 6
3 10

*/