#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define MAX_M 10000
#define MAX_N 2001

int n,m,cnt,maxLen,pre[MAX_N];

struct Edge{
    int u,v,w;
}edge[MAX_M];

bool cmp(Edge e1,Edge e2){
    return e1.w<e2.w;
}

int find(int x){  				//改进查找算法：完成路径压缩，将 x的上级直接变为根结点，那么树的高度就会大大降低 

    if(pre[x] == x) return x;		//递归出口：x的上级为 x本身，即 x为根结点 
    return pre[x] = find(pre[x]);   //此代码相当于先找到根结点 rootx，然后 pre[x]=rootx 
} 
bool isSame(int x, int y)      		//判断两个结点是否连通 
{
    return find(x) == find(y);  	//判断两个结点的根结点（即代表元）是否相同 
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    sort(edge,edge+m,cmp);
    for(int i=1; i<=n; i++){
        pre[i]=i;     			//每个结点的上级都是自己 
    } 

    for(int i=0;i<m;i++){

        if(! isSame(edge[i].u,edge[i].v)){
            int pre1=find(edge[i].u);
            int pre2=find(edge[i].v);
            pre[pre1]=pre2;   
            cnt++;
            maxLen=max(maxLen,edge[i].w);
        }
        if(cnt==n-1)
            break;
    }
    cout<<maxLen<<endl;
    system("pause");
    return 0;
}

/*
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4

3

3 3
1 2 23
2 3 1000
1 3 43

43
*/



/*
    Kruskal算法
    此算法可以称为“加边法”，初始最小生成树边数为0，每迭代一次就选择一条满足条件的最小代价边，加入到最小生成树的边集合里。 
    1. 把图中的所有边按代价从小到大排序； 
    2. 把图中的n个顶点看成独立的n棵树组成的森林； 
    3. 按权值从小到大选择边，所选的边连接的两个顶点ui,viui,vi,应属于两颗不同的树，
        则成为最小生成树的一条边，并将这两颗树合并作为一颗树。 
    4. 重复(3),直到所有顶点都在一颗树内或者有n-1条边为止。
*/
