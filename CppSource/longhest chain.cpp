#include <cstdio>
#include <cstring>
#include<iostream>
 
int n,l[100001] = {0},r[100001]={0},fa[100001] = {0},ma = 0,k =0;
bool bo[100001];
 
void sear_ch(int x,int tt) //表示走到了x这个点，已经走过的距离为tt 
{
	bo[x] = false;
	if (tt > ma) //如果能够更新最大距离则更新 
		{
			ma = tt;
			k = x;
		}
	if (bo[fa[x]]) //接下来这三行。查看是否能访问与之相连的节点。如果能就递增距离并访问 
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
			fa[r[i]] = i; //记录下这个节点的左儿子和右儿子的信息 
		}
	memset(bo,true,sizeof(bo));	//重置判重数组 
	bo[0] = false;	 //bo[0]=false便于判断某节点是否有左儿子或有儿子。 连同判重一起用一个bo数组 
	sear_ch(1,1);//从任意一个节点找离这个点最远的点k 
	memset(bo,true,sizeof(bo));
	bo[0] = false;
	ma = 0;
	sear_ch(k,1);//然后从点k开始再找一次离k最远的点m 
	printf("%d\n",ma-1);//ma是这两个点之间的点的个数。要求的是边的个数 
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