#include<iostream>
using namespace std;
#define maxLen 100000
int data[maxLen];

int binsearch(int num,int length){
    int left,right,med;
    left=0;
    right=length-1;
    med=(left+right)/2;

    if(data[left]>=num)
        return data[left];
    if(data[right]<=num)
        return data[right];

    while(left<right){
        if(data[med]>num){
            right=med-1;
        }
        else if(data[med]<num){
            left=med+1;
        }
        else{
            return data[med];
            break;
        }
        med=(left+right)/2;

    }

    if(data[med]>num){
        int dif1=abs(data[med-1]-num);
        int dif2=abs(data[med]-num);
        return dif1>dif2?data[med]:data[med-1];
    }
    else{
        int dif1=abs(data[med]-num);
        int dif2=abs(data[med+1]-num);
        return dif1>dif2?data[med+1]:data[med];
    }

}

int main(){
    int n;//1<=n<=100000
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>data[i];
        }
        int m;//1<=m<=10000
        cin>>m;
        int closedDate[m];
        for(int i=0;i<m;i++){
            int num;
            cin>>num;        
            closedDate[i]=binsearch(num,n);
        }
        for(int i=0;i<m;i++)
            cout<<closedDate[i]<<endl;

    }
    return 0;
}