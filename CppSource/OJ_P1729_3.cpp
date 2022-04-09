#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

/*
    ！！！随机选择一个没有朝向正面的灯进行旋转

    AC了(但是需要进行优化)
*/

#define MAX_N 15
int n;
int f[MAX_N],cnt[MAX_N],dir[MAX_N][MAX_N];

bool isend(){
    for(int i=1;i<=n;i++)
        if(f[i]!=1)
            return false;
    return true;
}

void action(int hit){
    if(isend()){
        for(int j=1;j<=n;j++)
            cout<<cnt[j]<<" ";
        cout<<endl;
        system("pause");
        exit(0);
    }
    if(f[hit]==1){
        hit=rand()%n+1;
        action(hit);
    }
    cnt[hit]++;
    for(int j=1;j<=n;j++){
        f[j]=f[j]%4+dir[hit][j];
    }
    action(rand()%n+1);
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
    action(rand()%n+1);
}