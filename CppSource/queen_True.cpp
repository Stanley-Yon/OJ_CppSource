#include<iostream>
#include<string.h>
using namespace std;
int queens[9]={0};
int unfinished[8]={0};//记录未摆放皇后的行
int allUnfinished=0;
int k=0;//作为unfinished的监测员
int cnt=0;

/*行已经避免，无需再次进行验证
queens[i]在比较时应该判断是否为0，而且判断应该放在if语句里
如果放在for语句里可能会造成后面的不进入判断，例如 6 8 行有皇后在，
可是因为前面 4或5为0,而造成for循环不到这两个项目
*/
bool isConflict(int m,int n){//m  n为点的坐标
    for(int i=1;i<=8;i++){
        if(queens[i]!=0 && queens[i]==n)//与列冲突
            return true;
        if(queens[i]!=0 && abs(m-i)==abs(n-queens[i]))
            return true;
    }
    return false;
}
void queen(int c){
    if(k==allUnfinished){
        cnt++;
        return;
    }
    for(int j=1;j<=8;j++){
        if(!isConflict(c,j)){
            queens[c]=j;
            ++k;
            queen(unfinished[k]);
            queens[c]=0;
            --k;
        }
    }
}

int main(){
    int x;
    while(cin>>x){
        memset(queens,0,sizeof(queens));
        memset(unfinished,0,sizeof(unfinished));
        allUnfinished=0;
        k=0;
        cnt=0;

        int flag=0;
        if(x==1){
            queens[1]=1; 
            flag=1;                     
        } 
        for(int j=2;j<=8;j++){
            cin>>x;
            if(x==1){
                queens[1]=j;
                flag=1;
            }           
        }
        if(!flag)
            unfinished[allUnfinished++]=1;

        for(int i=2;i<=8;i++){
            flag=0;
            for(int j=1;j<=8;j++){
                cin>>x;
                if(x==1){
                    queens[i]=j;
                    flag=1;
                }
            }
            if(!flag)
                unfinished[allUnfinished++]=i;//记录未完成的行
        }
        queen(unfinished[k]);
        cout<<cnt<<endl;
    }
    
    return 0;
}


/**
 * @brief 
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

 */