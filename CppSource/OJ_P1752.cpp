#include<iostream>
using namespace std;
int ways=0;

void dfs(int n){
    if(n==0){
        ways++;
        return;
    }
    for(int i=1;i<=n;i++){
        dfs(n-i);
    }

}

int main(){
    int n;//1<=n<=6
    while(cin>>n){
        dfs(n);
        cout<<ways<<endl;
        ways=0;
    }
    return 0;
}