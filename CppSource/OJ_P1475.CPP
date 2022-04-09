#include<iostream>
#include<algorithm>
using namespace std;

struct Game{
    int t;
    int p;
};

bool cmp(Game g1,Game g2){
    return g1.p>g2.p;
}

int main(){
    int award,n;
    while(cin>>award>>n){
        Game game[n+1];
        for(int i=1;i<=n;i++){
            cin>>game[i].t;
        }
        for(int i=1;i<=n;i++){
            cin>>game[i].p;
        }
        sort(game+1,game+n+1,cmp);
        int visited[n+1]={0};
        int pushment=0;
        for(int i=1;i<=n;i++){
            while(visited[game[i].t]!=0){
                game[i].t--;
            }
            if(game[i].t>0){
                visited[game[i].t]=1;
            }
            else{
                pushment+=game[i].p;
            }
        }
        cout<<award-pushment<<endl;
    }
    return 0;
}