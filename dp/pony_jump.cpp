/* ************************************************************************
> File Name:     pony_jump.cpp
> Author:        Daniel Wang
> 邮箱:          herrwangistcool@foxmail.com    
> Created Time:  Fri Mar 25 18:28:22 2022
> Description:   一个8×8的棋盘上有一个马初始位置为(a,b)，他想跳到(c,d)，问是否可以？如果可以，最少要跳几步？   
 ************************************************************************/

#include<iostream>
using namespace std;

int minSum=10000;

void dfs(int board[9][9], int a, int b, int N=-1){
    N++;
    // 如果N大于目前的最小步数，没必要继续判断
    if(N>minSum)    return;
    // 判断是否再棋盘内
    if(a>=1 && a<=8 && b>=1 && b<=8){
        // 如果跳到指定位置并步数小于当前最小步数
        if(board[a][b]==2 && N<minSum){
            // 把N赋值给minSum
            minSum=N;
            // 如果当前位置未被走过
        }else if(board[a][b]==0){
            // 标记当前位置已被走过
            board[a][b]=1;
            dfs(board, a-1, b-2, N);    dfs(board, a-2, b-1, N);
            dfs(board, a-2, b+1, N);    dfs(board, a-2, b+2, N);
            dfs(board, a+1, b+2, N);    dfs(board, a+2, b+1, N);
            dfs(board, a+2, b-1, N);    dfs(board, a+1, b-2, N);
            // 回溯，清除标记
            board[a][b]=0;
        }else return;
    }else return;
}
int main(){
    int board[9][9]={0};
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    board[c][d]=2;
    dfs(board,a,b);
    cout<<minSum;
    return 0;
}
