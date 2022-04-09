#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;
#define MAX_N 10000
#define INF 1e9
int n;
double res=INF;
int x[MAX_N],y[MAX_N];

double dis(double x1,double y1,double x2,double y2){
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        for(int j=i-1;j>=0;j--){
            double temp=dis(x[i],y[i],x[j],y[j]);
            res=min(temp,res);
        }
    }
    cout << fixed<<setprecision(4) << res <<endl;
    system("pause");
    return 0;
}

/*
    暴力求解不可取   QAQ

************************************

*/