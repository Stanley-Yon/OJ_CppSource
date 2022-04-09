#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=30;
int n,tot;//tot初始化 
int vis[maxn][3];
int C[maxn];
int f[maxn];//f把0到（剩余棋子个数-1）映射到还没有摆放棋子的行 
int k=0;//k表示剩余棋子个数 
 
void search(int c){//把cur换成c 
	if(c==k) tot++;//cur换成c n换为k 
	else {
		int cur=f[c];//映射 
		for(int i=0;i<8;i++)
            if(!vis[i][0]&&!vis[cur-i+8][1]&&!vis[cur+i][2]){
                C[cur]=i;
                vis[i][0]=vis[cur-i+8][1]=vis[cur+i][2]=1;
                search(c+1);//cur换成c 
                vis[i][0]=vis[cur-i+8][1]=vis[cur+i][2]=0;
		    }
		
	}
 
}
int main(){
	memset(vis,0,sizeof(vis));
	memset(C,0,sizeof(C));
	memset(f,0,sizeof(f));
	tot=0;
	int x;
	
	for(int i=0;i<8;i++){
        int flag=1;
        for(int j=0;j<8;j++){
            cin>>x;
            if(x==1){
                vis[j][0]=vis[i-j+8][1]=vis[i+j][2]=1;
                flag=0;
            }		
	    }
	    if(flag) f[k++]=i;
	}
	
	search(0);
	cout<<tot<<endl;
	system("pause");
	return 0;
} 