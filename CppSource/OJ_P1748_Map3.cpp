#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
#define  MAX_N 2000

int T,n,cnt;
int a[MAX_N],b[MAX_N],c[MAX_N],d[MAX_N];
unordered_map<int,int> mapSum;

int main(){
    cin>>T;
    while(T--){
        cnt=0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i]>>b[i]>>c[i]>>d[i];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mapSum[a[i]+b[j]]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mapSum.count(-c[i]-d[j]))
                    cnt+=mapSum[-c[i]-d[j]];
            }
        }
        cout<<cnt<<endl;
        system("pause");
    }
    return 0;
}