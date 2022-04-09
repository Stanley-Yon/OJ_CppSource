#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define MAX_N 15
int n;
int f[MAX_N],cnt[MAX_N],dir[MAX_N][MAX_N];

bool isValida(int hit){
    if(cnt[hit]==4)
        return true;
    return false;
}
bool isend(){
    for(int i=1;i<=n;i++)
        if(f[i]!=1)
            return false;
    return true;
}
void makeAction(int i){
    // if(i==0)    return;
    cnt[i]++;
    for(int j=1;j<=n;j++){
        f[j]=f[j]%4+dir[i][j];
    }
}
void backAction(int i){
    // if(i==0)    return;
    cnt[i]--;
    for(int j=1;j<=n;j++){
        if(f[j]==1 && dir[i][j]!=0 )
            f[j]=4;
        else
            f[j]-=dir[i][j];  
    }
}


void bfs(int hit){       //返回敲击的哪一个石柱
    if(isValida(hit))
        return;
    if(isend()){
        for(int j=1;j<=n;j++)
            cout<<cnt[j]<<" ";
        cout<<endl;
        system("pause");
        exit(0);
    }
  
    for(int j=1;j<=n;j++){
        makeAction(j);
        bfs(j);
        backAction(j);
    }
    return;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dir[i][j];
        }
    }
    memset(cnt,0,sizeof cnt);
    bfs(0);
    return 0;
}
