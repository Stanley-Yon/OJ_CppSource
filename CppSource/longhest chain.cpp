#include <cstdio>
#include <cstring>
#include<iostream>
 
int n,l[100001] = {0},r[100001]={0},fa[100001] = {0},ma = 0,k =0;
bool bo[100001];
 
void sear_ch(int x,int tt) //��ʾ�ߵ���x����㣬�Ѿ��߹��ľ���Ϊtt 
{
	bo[x] = false;
	if (tt > ma) //����ܹ���������������� 
		{
			ma = tt;
			k = x;
		}
	if (bo[fa[x]]) //�����������С��鿴�Ƿ��ܷ�����֮�����Ľڵ㡣����ܾ͵������벢���� 
		sear_ch(fa[x],tt+1);
	if (bo[l[x]])
		sear_ch(l[x],tt+1);
	if (bo[r[x]])
		sear_ch(r[x],tt+1);
}
 
int main()
{	
	//freopen("F:\\rush.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		{
			scanf("%d%d",&l[i],&r[i]);
			fa[l[i]] = i;
			fa[r[i]] = i; //��¼������ڵ������Ӻ��Ҷ��ӵ���Ϣ 
		}
	memset(bo,true,sizeof(bo));	//������������ 
	bo[0] = false;	 //bo[0]=false�����ж�ĳ�ڵ��Ƿ�������ӻ��ж��ӡ� ��ͬ����һ����һ��bo���� 
	sear_ch(1,1);//������һ���ڵ������������Զ�ĵ�k 
	memset(bo,true,sizeof(bo));
	bo[0] = false;
	ma = 0;
	sear_ch(k,1);//Ȼ��ӵ�k��ʼ����һ����k��Զ�ĵ�m 
	printf("%d\n",ma-1);//ma����������֮��ĵ�ĸ�����Ҫ����Ǳߵĸ��� 
    system("pause");
	return 0;
}


/*
6
2 3
4 5
0 6
0 0
0 0
0 0

4
*/