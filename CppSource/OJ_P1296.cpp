#include<iostream>
#include<math.h>
char universe[4000][4000];

using namespace std;

void dfs(double n,int x,int y){
    if(n==1){
         universe[x][y]='X';
         return;
    }
       
    int minSize=pow(3.0,n-2);
    dfs(n-1,x,y);
    dfs(n-1,x,y+2*minSize);
    dfs(n-1,x+minSize,y+minSize);
    dfs(n-1,x+2*minSize,y);
    dfs(n-1,x+2*minSize,y+2*minSize);
}

int main(){
    double n;
    while (cin>>n)
    {
        int dim=pow(3.0,n-1);
        for(int i=0;i<=dim;i++){
            for(int j=0;j<=dim;j++){
                universe[i][j]=' ';
            }
        }

        dfs(n,1,1);
        for(int i=1;i<=dim;i++){
            for(int j=1;j<=dim;j++){
                cout<<universe[i][j];
            }
            cout<<endl;
        }
        cout<<"-"<<endl;
        
    }
    
    return 0;
}