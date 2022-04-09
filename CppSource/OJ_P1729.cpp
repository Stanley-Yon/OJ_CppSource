#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdlib.h>
using namespace std;
#define MAX_N 15

int n;
int dir[MAX_N][MAX_N];
int f[MAX_N],cnt[MAX_N];

bool isValida(int hit){
    // for(int j=1;j<=n;j++){
    //     if(cnt[j]==4)
    //         return true;
    // }
    // return false;
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
    cnt[i]++;
    // if(i==0)
    //     return;
    for(int j=1;j<=n;j++){
        f[j]=f[j]%4+dir[i][j];
    }
}
void backAction(int i){
    cnt[i]--;
    // if(i==0)
    //     return;
    for(int j=1;j<=n;j++){
        if(f[j]==1 && dir[i][j]!=0 )
            f[j]=4;
        else
            f[j]-=dir[i][j];  
    }
}

// void dfs(int hit){       //返回敲击的哪一个石柱
//     if(isValida(hit))
//         return;
//     if(isend()){
//         for(int j=1;j<=n;j++)
//             cout<<cnt[j]<<" ";
//         cout<<endl;
//         system("pause");
//         exit(0);
//     }
//     makeAction(hit);
//     for(int j=1;j<=n;j++)
//         dfs(j);
//     backAction(hit);
//     return;
// }

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
        makeAction(hit);
        bfs(j);
        backAction(hit);
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
    bfs(0);
    return 0;
}

/*

4
4 2 1 2
1 0 1 0
0 1 1 0
0 0 1 0
1 0 0 1

2 3 3 3



13

4 4 1 2 3 4 2 3 1 3 2 4 1 
1 0 0 0 0 1 0 1 0 0 1 0 0
0 1 0 0 0 0 1 0 0 1 0 0 1
0 0 1 0 0 0 0 0 0 1 0 0 0
0 0 0 1 0 0 0 0 1 0 0 0 0
1 0 0 0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 1 0 0 0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 1 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 1 0 0 0 0 0 0 1



13

4 4 1 2 3 4 2 3 1 3 2 4 1 
1 0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 1

*/