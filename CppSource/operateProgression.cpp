#include<iostream>
using namespace std;

void buddle(unsigned long long arr[],int start,int len){
    for(int i=0;i<len-start-1;i++){         //ֻ��Ҫ���Ʋ������ˣ�ʵ���Ͼ���n�ν���󡢴����������뿿���λ��
        for(int j=start;j<len-i-1;j++){     //len-i-1����ÿһ�˵��������
            if(arr[j]>arr[j+1]){
                unsigned long long temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }         
        }
    }

}

int main(){
    int n;
    while(cin>>n){
        int lenght=0;
        unsigned long long num[n];
        for(int i=0;i<n;i++){
            cin>>num[i];
            lenght++;
        }

        for(int j=1,i=0;j<n;i++,j++){
            buddle(num,i,lenght);
            num[i+1]=num[i]*num[i+1]+1;
            // for(int k=i+1;k<lenght;k++){
            //     cout<<num[k]<<" ";
            // }
            // cout<<endl;
        }
        
        cout<<num[lenght-1]<<endl;

    }
    return 0;
}