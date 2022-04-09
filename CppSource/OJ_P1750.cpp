#include<iostream>
using namespace std;
#define maxNum 500500

int arr[maxNum]={0};
long long num=0;

/*
long long �洢���ݣ�int���ͻᱬ
*/

/***
 *  i < j && a[i] > a[j]) ˵��ֻҪ�����������ǰ�涼��Ҫ���к��������С�������н����ģ�
 * �����ǹ鲢���������¡�����ֻ��Ҫʹ�ñ�������¼���������Ĵ�������
*/
void split(int left,int right);
void merge(int left,int med,int right);

//ÿ�����ֲ���10^9,��n<=5*10^5 50��
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
            num=num+(long long)(med-i+1);//i��med���������Ժ�j�������ԣ�֮��j��������temp���У�j+1
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