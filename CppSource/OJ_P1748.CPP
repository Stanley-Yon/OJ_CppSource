#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 2001
/*
    运用分治发求解：
    1、首先将四列两两任意相加，并且其中一列结果取反
    2、sort一列的结果，用于二分查找
    3、从待查找一列中依次取值，利用二分法查找是否有等于的数

    AC代码

    注意  int+int很有可能超出int范围  和用long long!!!
*/

int T,n,cnt;
int a[MAX_N],b[MAX_N],c[MAX_N],d[MAX_N];
long long l[MAX_N*MAX_N],r[MAX_N*MAX_N];

bool cmp(long long a,long long b){
    return a<b;
}

void binarySort(int left,int right, long long r){
    int mid;
    while(left<=right){
        mid=(left+right)/2;
        if(l[mid]>r){
            right=mid-1;
            continue;
        }  
        else if(l[mid]<r){
            left=mid+1;
            continue;
        }
        else {
            int temp=mid;
            while (mid<=right && l[mid++]==r)
                cnt++;      
            mid=temp;
            while (mid>=left && l[--mid]==r)
                cnt++;
            return;
        }

    }
}

int main(){
    cin>>T;
    while (T--)
    {
        cnt=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i]>>c[i]>>d[i];
        }
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                l[k]=a[i]+b[j];
                r[k++]=-(c[i]+d[j]);
            }
        }
        sort(l,l+n*n,cmp);
        int left=0,right=n*n-1;
        for(int i=0;i<n*n;i++){
            binarySort(left,right,r[i]);
        }
        cout<<cnt<<endl;
        system("pause");
    }
    return 0;
}




void binarySort1(int left,int right, int r){
    if(left>=right)
        return;
    int mid=(left+right)/2;
    if(l[mid]>r)
        binarySort(left,mid,r);
    else if(l[mid]<r)
        binarySort(mid+1,right,r);
    else{
        int temp=mid;
        while (l[mid++]==r && mid<=right)
            cnt++;      
        mid=temp;
        while (mid>0 && l[--mid]==r)
            cnt++;
    }

}

/*

1
6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45 

5
*/