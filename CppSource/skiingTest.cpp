#include<iostream>
#include <stdio.h>
#include <string.h>
int a[105][105];//���ڽ������� 
int b[105][105]={0};//��ʼ��״̬��0��ʾ�õ�û���ù���֮���øõ�����ѩ���ȸ������ֵ 
int c[4][2]={{-1,0},{0,1},{1,0},{0,-1}};//��ʾ�ĸ�����x,y�ĸı�ֵ
int n,m;//���к���Ϊȫ�ֱ�������Ϊ����ĺ����ı�����Ҫ 
int maxlen(int i,int j);//���������ѩ���ȵĺ���
int main()
{
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	int max=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			b[i][j]=maxlen(i,j);//����õ�����ѩ���� 
			if(b[i][j]>max)	//�Ƚϸ������󳤶ȣ��ҵ������Ǹ�ֵ 
				max=b[i][j];
		}
	printf("%d",max);
    system("pause");
    return 0;	
	
}
int maxlen(int i,int j)
{
	if(b[i][j]!=0)	return b[i][j];
	int k,x,y;
	int s;int max=0;
	for(k=0;k<4;k++){
		x=i+c[k][0];
		y=j+c[k][1];
		if( (x>=0&&x<n) && (y>=0&&y<m) && (a[x][y]<a[i][j]) ){//�߽�������x,y�ڷ�Χ�ڣ��õ��ֵ��ԭ���ĵ��ֵҪС 
			s=maxlen(x,y);//����÷���ĵ�����ѩ���� 
			if(s>max)	max=s;//�Ƚϲ�����ĸ���������ѩ���� 
		}
	}
	b[i][j]=max+1;//֮ǰ����󳤶ȼ�������µĵ� 
	return max+1;
}