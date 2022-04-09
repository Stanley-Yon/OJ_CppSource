#include<iostream>
using namespace std;
#define maxLen 9999
int Graph[101][101];

void Floyed(int nodeNum){
    for(int k=1;k<=nodeNum;k++){
        for(int i=1;i<=nodeNum;i++){
            for(int j=1;j<=nodeNum;j++){
                if(Graph[i][k]!=maxLen && Graph[k][j]!=maxLen){
                    Graph[i][j]=min(Graph[i][j],max(Graph[i][k],Graph[k][j]));
                }
            }
        }
    }

}

int main(){
    int C,S,Q;
    int count=1;
    while(cin>>C>>S>>Q){
        if(!C||!S||!Q){
            cout<<"Case #"<<count<<endl,++count;
            cout<<"no path"<<endl;
            continue;
        }
            
        for(int i=1;i<=C;i++)
            for(int j=1;j<=C;j++)
                Graph[i][j]=maxLen;
        int u,v,w;
        for(int i=1;i<=S;i++){
            cin>>u>>v>>w;
            Graph[u][v]=Graph[v][u]=w;
        }
        int m[Q],n[Q];
        for(int i=0;i<Q;i++){
            cin>>m[i]>>n[i];           
        }

        Floyed(C);
        cout<<"Case #"<<count<<endl,++count;

        for(int i=0;i<Q;i++){
            if(Graph[m[i]][n[i]]!=maxLen)
                cout<<Graph[m[i]][n[i]]<<endl;
             else
                cout<<"no path"<<endl;      
        }
    }
    return 0;
}

