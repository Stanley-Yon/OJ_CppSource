#include<iostream>
using namespace std;
int value[500][1000];

int findMaxPath(int m,int n){
    int dp[m][n];
    dp[0][0]=value[0][0];
    for(int i=1;i<m;i++){
        dp[i][0]=value[i][0]+dp[i-1][0];
    }
    for(int j=1;j<n;j++){
        dp[0][j]=value[0][j]+dp[0][j-1];
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+value[i][j];
        }
    }

    return dp[m-1][n-1];

}

int max(int x,int y){
    return (x)>=(y)?(x):(y);
}

int main(){
    int m,n;//m>=1;n<=1000
    while(cin>>m>>n){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>value[i][j];
            }
        }

        int maxValue=findMaxPath(m,n);
        cout<<maxValue<<endl;


    }
    return 0;

}