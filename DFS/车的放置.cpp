/* ************************************************************************
> File Name:     车的放置.cpp
> Author:        Daniel Wang
> mail:          herrwangistcool@foxmail.com
> Created Time:  Mon Apr  4 23:57:47 2022
> Description:   在一个n*n的棋盘中，每个格子中至多放置一个车，且要保证任何两个车都不能相互攻击，有多少中放法(车与车之间是没有差别的)
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int N;
long long ans=1;    //刚开始什么也不放也属于一种答案
bool visited[10];   //标志被放置的列
void DFS(int step){ //表示从第step行开始放
    if(step>N)  return; //如果超出规定的棋盘边界，跳出
    for(int i=1; i<=N; i++){
        if(!visited[i]){    //如果这一列没有被放置
            visited[i]=true;    //在这个位置放置它
            ans++;  //该情况的答案加1
            DFS(step+1);    //肯定不能在同一行放了，跳到下一行
            visited[i]=false;   //回溯
        }
    }
    DFS(step+1);    //从step+1行继续放
}
int main(){
    cin>>N;
    DFS(1);  //从第一行开始搜
    cout<<ans;
    return 0;
}
