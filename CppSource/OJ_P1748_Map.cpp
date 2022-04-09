#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<algorithm>
using namespace std;
#define MAX_N 2000

/*
    ???? ????????
*/

int n,cnt;
int a[MAX_N],b[MAX_N],c[MAX_N],d[MAX_N];
map<int,int> mapSum;

int main(){
    int T;
    cin>>T;
    while(T--){
        cnt=0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i]>>b[i]>>c[i]>>d[i];

        pair< map<int,int>::iterator,bool > rent;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rent=mapSum.insert( pair<int,int>(a[i]+b[j],1) );
                if(!rent.second){
                    mapSum[a[i]+b[j]]+=1;
                }

            }
        }   
      
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mapSum.find(-c[i]-d[j])!=mapSum.end()){
                    cnt+=mapSum[-c[i]-d[j]];
                }
            }
        }
        cout<<cnt<<endl;
        system("pause");
    }
    return 0;
}


    // map< int,int > ll;
    // ll.insert(pair< int,int >(1,2) );

    // std::pair<map< int,int >::iterator,bool > ret;
    // ret=ll.insert(pair< int,int >(1,3) );