#include<bits/stdc++.h>
using namespace std;
#define MAX_N 14
int n,res=0;
int co[MAX_N],ro[MAX_N],cnt1;
int unfin[MAX_N],cnt2,k;

bool isConflict(int r,int c){   
    for(int i=0;i<cnt1;i++){
        if(co[i]==c || abs(co[i]-c)==abs(r-ro[i]) )
            return true;
    }
    return false;
}   

void dfs(int rw){
    if(k>=cnt2){
        res++;
        return;
    }

    for(int j=1;j<=8;j++)
    {
        if(!isConflict(rw,j))
        {
            ro[cnt1]=rw;
            co[cnt1++]=j;
            k++;
            dfs(unfin[k]);
            k--;
            ro[--cnt1]=0;
            co[cnt1]=0;
        }

    }

}

int main(){
    int a;
    for(int i=1;i<=8;i++){
        int flag=0;
        for(int j=1;j<=8;j++){
            cin>>a;
            if(a==1){
                ro[cnt1]=i;
                co[cnt1++]=j;
                flag=1;
            }
        }
        if(!flag){
            unfin[cnt2++]=i;
        }
    }

    dfs(unfin[k]);
    cout<<res<<endl;
    system("pause");
    return 0;
}


/*

0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0


0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

*/