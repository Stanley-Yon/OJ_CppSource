/*
    prim�㷨  
    ���㷨���Գ�Ϊ���ӵ㷨����ÿ�ε���ѡ�������С�ı߶�Ӧ�ĵ㣬���뵽��С�������С��㷨��ĳһ������s��ʼ���𽥳��󸲸�������ͨ�������ж��㡣

    ͼ�����ж��㼯��ΪVV����ʼ���u={s},v=V?uu={s},v=V?u;
    ����������u,vu,v�ܹ���ɵı��У�ѡ��һ��������С�ı�(u0,v0)(u0,v0)�����뵽��С�������У�����v0v0���뵽����u�С�
    �ظ��������裬ֱ����С��������n-1���߻���n������Ϊֹ��
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
int dis[5000+10][5000+10],minn[6000];       //dis��������룬minn���ֵ
bool vis[6000];         //��¼�������
ll sum;             //�����ۼ�

int main(){
	int n,m;
	scanf("%d%d",&n,&m);

    memset(dis,INF,sizeof(dis));//��ʼ��
    int x,y,z;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        dis[x][y]=min(dis[x][y],z);//˫��ͼ��ͼ���ڼ���
        dis[y][x]=min(dis[y][x],z);
    }

    memset(vis,false,sizeof(vis));//������ʼ��
    memset(minn,INF,sizeof(minn));
    minn[1]=0;


    for(int i=1;i<=n;i++){          //Primģ�忪ʼ
        int k=0;
        for(int j=1;j<=n;j++)
            if(!vis[j]&& minn[j]<minn[k] )//�ҵ�
                k=j;
        vis[k]=true;            //����ѷ���
        for(int j=1;j<=n;j++)
            if(!vis[j])
                minn[j]=min(minn[j],dis[k][j]);        //������Сֵ
    }

    for(int i=1;i<=n;i++)
        sum=max((ll)minn[i],sum);       //�����ֵ
    printf("%lld",sum);
	return 0;
}