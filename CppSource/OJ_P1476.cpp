#include<iostream>
#include<algorithm>
using namespace std;
#define N 1000

struct work{
    int timeA;
    int timeB;
};

struct work querry[N];
struct work N1[N];
struct work N2[N];

bool cmp1(work w1,work w2);
bool cmp2(work w1,work w2);

int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>querry[i].timeA;
        }
        for(int i=0;i<n;i++){
            cin>>querry[i].timeB;
        }

        int len1=0,len2=0;
        for(int i=0;i<n;i++){
            if(querry[i].timeA<=querry[i].timeB){
                N1[len1].timeA=querry[i].timeA;
                N1[len1++].timeB=querry[i].timeB;
            }
            else{
                N2[len2].timeA=querry[i].timeA;
                N2[len2++].timeB=querry[i].timeB;
            }
        }
        
        sort(N1,N1+len1,cmp1);//0~len-1½øÐÐÅÅÐò
        sort(N2,N2+len2,cmp2);
        
        int k=0;
        int i=0,j=0;
        while(i<len1){
            querry[k++]=N1[i++];
        }
        while(j<len2){
            querry[k++]=N2[j++];
        }
        i=0;
        int f1=0,f2=0;
        for(;i<len1+len2;i++){
            f1=f1+querry[i].timeA;
            f2=max(f2,f1)+querry[i].timeB;
        }
        cout<<f2<<endl;
    }
    return 0;   
}

bool cmp1(work w1,work w2){
    return w1.timeA<=w2.timeA;
}
bool cmp2(work w1,work w2){
    return w1.timeB>=w2.timeB;
}