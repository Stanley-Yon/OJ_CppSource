#include<iostream>
using namespace std;
#define MAX_N 500500
int n;
long long cnt;
int data[MAX_N];

void mergeSort(int left,int right){
    if(left>=right)
        return;
    int mid=(left+right)/2;
    int i=left,j=mid+1;
    mergeSort(left,mid);
    mergeSort(mid+1,right);
    
    int temp[right-left+1];
    int k=0;
    while(i<=mid && j<=right){
        if(data[i]>data[j]){
            temp[k++]=data[j++];
            cnt+=mid-i+1;
        }
        else 
            temp[k++]=data[i++];
    }
    while(i<=mid){
        temp[k++]=data[i++];
    }
    while(j<=right){
        temp[k++]=data[j++];
    }
    k=0;
    for(i=left;i<=right;i++){
        data[i]=temp[k++];
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    int left=0,right=n-1;
    mergeSort(left,right);
    cout<<cnt<<endl;
    system("pause");
}