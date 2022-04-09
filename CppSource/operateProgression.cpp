#include<iostream>
using namespace std;

void buddle(unsigned long long arr[],int start,int len){
    for(int i=0;i<len-start-1;i++){         //只需要控制操作几趟，实际上就是n次将最大、次最大的数放入靠后的位置
        for(int j=start;j<len-i-1;j++){     //len-i-1表明每一趟到哪里结束
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