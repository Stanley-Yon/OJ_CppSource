#include<iostream>
using namespace std;
#define maxNum 500500

int arr[maxNum]={0};
long long num=0;

/*
long long 存储数据，int类型会爆
*/

/***
 *  i < j && a[i] > a[j]) 说明只要大的数在数组前面都需要进行和数组后面小的数进行交换的，
 * 这正是归并排序做的事。我们只需要使用变量来记录计数交换的次数即可
*/
void split(int left,int right);
void merge(int left,int med,int right);

//每个数字不超10^9,且n<=5*10^5 50万
int main(){
    int n;
    while(cin>>n){
        num=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int left=0,right=n-1;
        split(left,right); 
        cout<<num<<endl;
        system("pause");
    }
    return 0;
}

void split(int left,int right){
    if(left>=right)
        return;
    int med=(left+right)/2;
    split(left,med);
    split(med+1,right);
    merge(left,med,right);
}

void merge(int left,int med,int right){
    int temp[right-left+1];

    int i=left,j=med+1;
    int k=0;
    while(i<=med && j<=right){
        if(arr[i]>arr[j]){
            temp[k++]=arr[j++];
            num=num+(long long)(med-i+1);//i到med的数都可以和j组成逆序对，之后j的数进入temp当中，j+1
        }
        else
            temp[k++]=arr[i++];
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
    for(int j=left;j<=right;j++){
        arr[j]=temp[k++];
    }
}

/*


6
5 4 2 6 3 1

11



11
23 13 35 6 19 50 28 38 26 17 45


21
*/