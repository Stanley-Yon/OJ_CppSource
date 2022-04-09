#include<bits/stdc++.h>
using namespace std;
#define MAX_N 31
#define MAX_V (int)2e5+1
int n,V;
int v[MAX_N],w[MAX_N];
int dp[MAX_N][MAX_V];

int main(){
    while(cin>>V>>n)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            cin>>v[i]>>w[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=V;j++)
            {
                if(v[i]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
            }
        }
        cout<<dp[n][V]<<endl;
    }

    system("pause");
    return 0;
}