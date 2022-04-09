#include<iostream>
#include<string.h>
using namespace std;
int queens[9]={0};
int unfinished[8]={0};//��¼δ�ڷŻʺ����
int allUnfinished=0;
int k=0;//��Ϊunfinished�ļ��Ա
int cnt=0;

/*���Ѿ����⣬�����ٴν�����֤
queens[i]�ڱȽ�ʱӦ���ж��Ƿ�Ϊ0�������ж�Ӧ�÷���if�����
�������for�������ܻ���ɺ���Ĳ������жϣ����� 6 8 ���лʺ��ڣ�
������Ϊǰ�� 4��5Ϊ0,�����forѭ��������������Ŀ
*/
bool isConflict(int m,int n){//m  nΪ�������
    for(int i=1;i<=8;i++){
        if(queens[i]!=0 && queens[i]==n)//���г�ͻ
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
                unfinished[allUnfinished++]=i;//��¼δ��ɵ���
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