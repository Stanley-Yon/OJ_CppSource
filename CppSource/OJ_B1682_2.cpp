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

int find(int x){  				//�Ľ������㷨�����·��ѹ������ x���ϼ�ֱ�ӱ�Ϊ����㣬��ô���ĸ߶Ⱦͻ��󽵵� 

    if(pre[x] == x) return x;		//�ݹ���ڣ�x���ϼ�Ϊ x������ xΪ����� 
    return pre[x] = find(pre[x]);   //�˴����൱�����ҵ������ rootx��Ȼ�� pre[x]=rootx 
} 
bool isSame(int x, int y)      		//�ж���������Ƿ���ͨ 
{
    return find(x) == find(y);  	//�ж��������ĸ���㣨������Ԫ���Ƿ���ͬ 
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    sort(edge,edge+m,cmp);
    for(int i=1; i<=n; i++){
        pre[i]=i;     			//ÿ�������ϼ������Լ� 
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
    Kruskal�㷨
    ���㷨���Գ�Ϊ���ӱ߷�������ʼ��С����������Ϊ0��ÿ����һ�ξ�ѡ��һ��������������С���۱ߣ����뵽��С�������ı߼���� 
    1. ��ͼ�е����б߰����۴�С�������� 
    2. ��ͼ�е�n�����㿴�ɶ�����n������ɵ�ɭ�֣� 
    3. ��Ȩֵ��С����ѡ��ߣ���ѡ�ı����ӵ���������ui,viui,vi,Ӧ�������Ų�ͬ������
        ���Ϊ��С��������һ���ߣ��������������ϲ���Ϊһ������ 
    4. �ظ�(3),ֱ�����ж��㶼��һ�����ڻ�����n-1����Ϊֹ��
*/
