#include<iostream>
using namespace std;
#define maxLen 100000
int array[maxLen];

int binSearch(int left,int right,int num){
    if(num<array[0])
        return -1;
    int med=(left+right)/2;
    while(left<right-1){
        if(array[med]==num)
            return array[med];
        else if(array[med]<num){
            left=med;
        }else{
            right=med;
        }
        med=(left+right)/2;
    }
    
    if(array[right]<=num)
        return array[right];
    else   
        return array[left];

}

int main(){
    int n,m;
    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            cin>>array[i];
        }
        int result[m]={-1};
        int num;
        for(int i=0;i<m;i++){
            cin>>num;
            result[i]=binSearch(0,n-1,num);           
        }
        for(int i=0;i<m;i++){
            cout<<result[i]<<endl;        
        }
    }
    return 0;
}
