#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        int lifetime[n];
        int maxTime=0,sum=0;
        for(int i=0;i<n;i++){
            cin>>lifetime[i];
            if(lifetime[i]>maxTime)
                maxTime=lifetime[i];
            sum+=lifetime[i];
        }
        sum=sum-maxTime;
        if(sum>maxTime){
            double result=(sum+maxTime)*1.0/2;
            cout<<setiosflags(ios::fixed)<<setprecision(1)<<result<<endl;
        }
        else
            cout<<setiosflags(ios::fixed)<<setprecision(1)<<sum*1.0<<endl;

    }
}