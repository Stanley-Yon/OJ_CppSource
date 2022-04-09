#include<iostream>
using namespace std;

int maxSubsegment(int arr[],int len){
    int maxSum=0;
    int tempSum=0;
    for(int i=0;i<len;i++){
        tempSum=max(tempSum+arr[i],arr[i]);
        maxSum=max(maxSum,tempSum);
    }
    return maxSum;

}

int max(int x,int y){
    return(x)>(y)?(x):(y);
} 

int main(){
    int n;//m<=10000
    while(cin>>n){
        int data[n];
        for(int i=0;i<n;i++){
            cin>>data[i];
        }      
        cout<<maxSubsegment(data,n)<<endl;

    }
    return 0;

}


    // 时间复杂度为 O(n^3)
    // 三层循环
     
    // int maxSum1() {
    //     int maxSum = 0;             //存储最大子段和
    //     int tempSum;                //临时存储最大子段和
    //     for (int i = 0; i < array.length - 1; i++) {
    //         for (int j = i; j < array.length; j++) {
    //             tempSum = 0;
    //             for (int k = i; k <= j; k++) {
    //                 tempSum += array[k];
    //                 if (tempSum > maxSum) {
    //                     maxSum = tempSum;
    //                 }
    //             }
    //         }
    //     }
    //     return maxSum;
    // }