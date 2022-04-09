#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
#define MAX_N 5005
#define INF 0x3f3f3f3f3f3f

int T,n,cnt;
long long maxl;
long long g[MAX_N][MAX_N];
long long dis[MAX_N];
struct NODE{
    long long x,y;
}node[MAX_N];

long long getDis(NODE n1,NODE n2){
    return (n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y);
}

void prim(){
    for(int i=0;i<n;i++)
        dis[i]=g[0][i];
    dis[0]=INF;    
    for(int i=1;i<n;i++){
        int minN=0;
        for(int i=0;i<n;i++){
            if(dis[i]<=dis[minN] && dis[i]!=0)
                minN=i;
        }
        int to=0;
        for(int i=0;i<n;i++){
            if(dis[i]==INF && dis[i]!=0 && g[minN][to]>g[minN][i])   //Ѱ�Ҹõ�ĸ��� 
                to=i;
        }
        dis[minN]=INF;// ����õ�
        maxl=max(maxl,g[minN][to]);
        for(int i=0;i<n;i++){
            if(dis[i]!=INF && dis[i]!=0)
                dis[i]=min(dis[i],g[minN][i]);
        }
    }

}

int main(){
    cin>>T;
    while (T--)
    {
        maxl=0;
        memset(dis,0,sizeof(dis));
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>node[i].x>>node[i].y;
            for(int j=i-1;j>=0;j--){
                g[i][j]=g[j][i]=getDis(node[i],node[j]);
            }
        }
        prim();
        cout<<maxl<<endl;
        system("pause");
    }
    return 0;
}


// long long getDis(NODE n1,NODE n2){
//     return pow((n1.x-n2.x),2)+pow((n1.y-n2.y),2);
// }
void prim1(){
    dis[0]=INF;//dis=INF��ʱ��˵���õ��Ѿ���������ͨͼ�������Ȱ� 0�ڵ����� 
	for(int i=1;i<n;i++)//��ʼ��һ��dist 
		dis[i]=g[0][i];
	for(int i=1;i<=n;i++)//ÿ��ѭ����������һ���㣬ѭ��n��ȫ������ 
	{
		int min1=0;
		for(int i=2;i<=n;i++)//��һ��û�б���¼�ĵ�������С��dist����Ϊ����¼�ĵ��Ѿ���INF�ˣ� ��Ҳ��������С��ά�����Ż� 
			if(dis[i]<dis[min1])
				min1=i;
		int from=1;
		for(int i=1;i<=n;i++)//��һ������㱻�����ʱ�������ĸ���Ϊ����
			if(dis[i]==INF&&g[from][min1]>g[i][min1])
				from=i;
		dis[min1]=INF;//��ʾ������Ѿ������� 
		maxl=max(maxl,g[from][min1]);//����ans 
		for(int i=1;i<=n;i++)//��û�б�����ĵ�������±�Ӱ����dist�ĵ� 
		{
			if(dis[i]!=INF)
				dis[i]=min(g[min1][i],dis[i]);
		}
    }
}