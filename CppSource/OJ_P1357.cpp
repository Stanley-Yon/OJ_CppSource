#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
#define MAX_M 1001
#define MAX_N 1001

int head[MAX_M],cnt,n,m;
queue<int> q;
int ru[MAX_N],ans[MAX_N],res;
/*
    head[i]��ʾ����iΪ�������һ���ߵĴ洢��ַ

    ǰ����������ʱ�Ǵ�����ߵ�����ʼ��    
*/

struct Edge{
    int to;      //��i���ߵ��ս��
    int next;   //���i����ͬ������һ���ߵĴ洢��ַ
}edge[MAX_M];

void add(int u,int v){
    edge[++cnt].to=v;
    edge[cnt].next=head[u]; 
    head[u]=cnt;
}

void bfs(){
    for(int i=1;i<=n;i++){
        if(!ru[i]) {
            q.push(i);
        }
    }
    while(!q.empty()){
        int p=q.front(); q.pop();
        for(int i=head[p];i>0;i=edge[i].next)
        {
            int tto=edge[i].to;
            ans[tto]=max(ans[tto],ans[p]+1);
            res=max(res,ans[tto]);
            ru[tto]--;
            if(!ru[tto])
                q.push(tto);
        }  

    } 


}

int main(){
    while(cin>>n>>m){
        cnt=0,res=0;
        memset(head,0,sizeof(head)), memset(ru,0,sizeof(ru)); 
        for(int i=1;i<=n;i++)
            ans[i]=1;
        int u,v;
        for(int i=1;i<=m;i++){
            cin>>u>>v;
            add(u,v);
            ru[v]++;
        }
        bfs();
        // for(int i=1;i<=n;i++)
        //     res=max(res,ans[i]);
        cout<<res<<endl;
    }
    return 0;
}

/*
������
    Ѱ�������ģ���⣺
        ����ʱע�⽫�丸�ڵ���ӽڵ����ǰ�������ߣ���Ȩ������Ϊ1
        �����һ���㣬Ҳ���Ǹ��ڵ㣬Ȼ����һ��DFS��Ѱ�����ֵ�����Ҽ�¼�����ֵ�ı�ţ�
        Ȼ���ٴӴ˱����һ��DFS,���õ�һ�����ֵ,��Ϊ����.

*/

/*

10 16
1 2
1 4
1 10
2 3
2 5
4 3
4 5
4 8
6 8
7 6
7 9
8 5
9 8
10 6
10 7
10 9

6

*/