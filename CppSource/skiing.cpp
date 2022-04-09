#include<iostream>
#include<string.h>
using namespace std;
int R,C;//R>=1,C<=100
int area[101][101];//第一行第一列开始
int maxlength=1;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

struct node{
    int x;
    int y;
    int value;
};

void bubble(struct node *s,int length){
    for(int i=0;i<length;i++){
        for(int j=0;j<length-i-1;j++){
            if(s[j].value>s[j+1].value){
                struct node temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}

int main(){
    while(cin>>R>>C){
        memset(area,0,sizeof(area));
        int maxlen[R+1][C+1];
        struct node queue[R*C];

        int tot=0;
        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++){
                cin>>area[i][j];
                maxlen[i][j]=1;
                queue[tot].x=i;
                queue[tot].y=j;
                queue[tot].value=area[i][j];
                tot++;
            } 
               
        bubble(queue,tot);

        for(int i=0;i<tot;i++){
            for(int k=0;k<4;k++){//尝试向4个方向运动
                int x1=queue[i].x+dir[k][0];
                int y1=queue[i].y+dir[k][1];
                bool nextStep=(x1<=R&&x1>=1)&&(y1>=1&&y1<=C);
                if(nextStep){
                    struct  node s0;
                    s0.value=area[x1][y1];
                    if(queue[i].value<s0.value){
                        //与原来的比较，是否更新**************
                        maxlen[x1][y1]=max(maxlen[x1][y1],maxlen[queue[i].x][queue[i].y]+1);
                        maxlength=maxlen[x1][y1]>maxlength?(maxlen[x1][y1]):maxlength;
                    }       
                }

            }
        }
        cout<<maxlength<<endl;
        maxlength=1;//重新设定maxlength的值，全局变量
    }
    return 0;

}

/*

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
res:25


2 3
1 2 3
4 5 6
res:4

3 3
6 6 6
6 6 6
6 6 6
res:1

1 5
3 2 4 3 2
res:3


两个相等的数据
25 6 
9901 6836 5761 3419 2163 4947 
1459 1661 7869 3074 4206 7688 
5039 3007 5821 7243 7570 9624 
3143 1664 9324 8214 8315 6499 
7571 9260 90 5788 7387 35 
6961 8425 7620 214 2791 4423 
324 9235 711 4442 5272 1890 
4398 5314 7868 1210 831 9271 
2596 5370 8717 4951 5544 6383 
7699 4997 7265 9387 9507 4902 
9074 5586 6214 1867 2793 6895 
9259 5859 7104 3927 1378 7434 
8547 4450 1535 7044 6135 2321 
1782 6571 3066 3565 2141 6340 
2447 7121 4142 4264 5524 6383 
2659 2039 6437 3650 4117 6981 
2907 3663 7945 4465 7491 1818 
4489 2583 8752 5314 6735 3660 
7004 5973 6725 6970 388 878 
4917 8309 9621 6519 8654 71 
4243 5130 4570 7259 6063 6906 
1779 2406 3358 7925 1559 5582 
113 9838 9437 9919 2620 132 
1346 7942 5667 779 761 1053 
5964 3884 8778 7739 9745 6488 

res:8

*/