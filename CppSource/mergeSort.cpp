#include<iostream>
using namespace std;
#define maxNum 500000

int data[maxNum];
int dataCopy[maxNum];
int num=0;

/***
 * 选择合适的排序方法，将原数组排序好后的新数组用作参考
*/
void split(int arr[],int left,int right);
void merge(int arr[],int left,int med,int right);

//每个数字不超10^9,且n<=5*10^5
int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>data[i];
        }
        int left=0,right=n-1;
        split(data,left,right);   
    }
    return 0;

}

void split(int arr[],int left,int right){
    if(left>=right)
        return;
    int med=(left+right)/2;
    split(arr,left,med);
    split(arr,med+1,right);
    merge(arr,left,med,right);

}

void merge(int arr[],int left,int med,int right){
    int temp[right-left+1];

    int i=left,j=med+1;
    int k=0;
    while(i<=med&&j<=right){
        if(arr[i]>=arr[j]){
            temp[k++]=arr[j++];
        }
        else{
            temp[k++]=arr[i++];
        }
    }
    while(i<=med){
        temp[k++]=arr[i];
        i++;
    }
    while(j<=right){
        temp[k++]=arr[j];
        j++;
    }

    k=0;
    for(int j=left;k<right-left+1;k++){
        arr[j]=temp[k];
        j++;
    }

}