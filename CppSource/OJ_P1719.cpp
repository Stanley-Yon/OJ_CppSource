#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
#define MAX_N 300001

int n,k,cnt=0;    //cnt记录k的个数
int num[MAX_N];

int findclosest(int k){     //n次幂
    int i;
    for(i=0;;i++){
        if((int)pow(2,i)>k)
            break;
    }
    return pow(2,i-1);
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>num[i];    
    }
    int bf;
    for(int i=1;i<=n;i++){
        bf=findclosest(i);
        if(num[i]!=k)
            continue;
        int dis=i-bf;
        if(dis<=cnt)
            cnt++;
        else
            cnt=dis+1;
    }
    cout<<cnt<<endl;
    system("pause");
}

/**
16  4
1 2 4 2 5 4 4 4 2  1  1  0  2  4  3  2

7
 */




