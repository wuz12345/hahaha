//棋盘覆盖问题
//采用分治法
//编译环境g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
//吴壮  化学研究所 201828003208016
#include <iostream>
#include <math.h>
using namespace std;
const int MAX = 1024 ; //k<=10
int chess[MAX][MAX];
int num=0;
void  chessboard(int Cen_row,int Cen_col,int x,int y,int K){
    if(K==1)
       return;
    int s=K/2;
    int R=Cen_row+s;
    int C=Cen_col+s;
    num++;
    int t=num;
    //A11
    if(x<R&&y<C){
        chessboard(Cen_row,Cen_col,x,y,s);
    }else{
        chess[R-1][C-1]=t;
        chessboard(Cen_row,Cen_col,R-1,C-1,s);
    }
    //A12
    if(x<R&&y>=C){
        chessboard(Cen_row,C,x,y,s);
    }else{
        chess[R-1][C]=t;
        chessboard(Cen_row,C,R-1,C,s);
    }
    //A21
    if(y<C&&x>=R){
        chessboard(R,Cen_col,x,y,s);
    }else{
        chess[R][C-1]=t;
        chessboard(R,Cen_col,R,C-1,s);
    }
    //A22
    if(x>=R&&y>=C){
        chessboard(R,C,x,y,s);
    }else{
        chess[R][C]=t;
        chessboard(R,C,R,C,s);
    }
}

int main() {
    int k;
 while(1){
    cout<<"请输入k(k<=10),(k<=1退出)：";
    cin>>k;    
    if(k<=1)
      return 0 ;
    int g=pow(2,k);
    int x,y;
    cout<<"请输入特殊点的位置：(x,y)";
    cin>>x>>y;
    chess[x][y]=num;
    chessboard(0,0,x,y,g);
    cout<<"****************result*****************"<<endl;
    for(int i = 0; i < g; i++){
      for(int j = 0; j < g; j++){
         cout << chess[i][j] << "\t";
      }
      cout<<endl<<endl<< endl;
    }
}
    return 0;
}

