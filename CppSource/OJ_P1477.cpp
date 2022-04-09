#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

struct heap{
        int weight;
        int value;
        double perValue;
};
// void QuickSort(heap arr[],int left,int right);
heap treasure[100];

bool cmp(heap p1,heap p2){
    return p1.perValue<p2.perValue;
}

int main(){
    int N,T;
    while(cin>>N>>T){
        int w,v;
        for(int i=0;i<N;i++){
            cin>>treasure[i].weight;
            cin>>treasure[i].value;
            treasure[i].perValue=treasure[i].value*1.0/(treasure[i].weight*1.0);
        }

        // QuickSort(treasure,0,N-1);
        sort(treasure,treasure+N,cmp);

        int i=N-1;
        double sumValue=0;
        while (T>0)
        {
            if(treasure[i].weight<=T){
                sumValue=sumValue+treasure[i].value;
                T=T-treasure[i].weight;
            }
            else{
                sumValue=sumValue+(double)T*treasure[i].perValue;
                break;
            }
            i--;

            //当全部放入的时候直接跳出*****
            if(i<0)
                break;
            
        }
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<sumValue<<endl;

    }
    return 0;
}

// void QuickSort(heap arr[],int left,int right){
//     if(left>=right)
//         return;
//     double base=arr[left].perValue;
//     int i=left,j=right;
//     while(i<j){
//         while(arr[j].perValue>base && j>i){
//             j--;
//         }
//         while(arr[i].perValue<base && i<j){
//             i++;
//         }
//         if(j>i){
//             heap temp=arr[i];
//             arr[i]=arr[j];
//             arr[j]=temp;
//         } 
//     }

//     QuickSort(arr,left,i-1);
//     QuickSort(arr,i+1,right);
// }


/**
 * 没有setiosflags(ios::fixed)时，会输出数据的有效位数
 * 位数不足时以指数的形势输出
 */