/* ************************************************************************
> File Name:     pick_coin.cpp
> Author:        Daniel Wang
> Mail:          Herrwangistcool@foxmail.com
> Created Time:  Mon Mar 14 19:52:22 2022
> Description:   有一个N x N的方格,每一个格子都有一些金币,只要站在格子里就能拿到里面的金币。你站在最左上角的格子里,每次可以从一个格子走到它右边或下边的格子里。请问如何走才能拿到最多的金币。
                 输入格式第一行输入一个正整数n。
             　　以下n行描述该方格。金币数保证是不超过1000的正整数。
                 输出格式最多能拿金币数量。
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int coins[1000][1000];
int state[1000][1000];

int walk_recursion(int coins[1000][1000], int i, int j){
    /*
        递归法：递归调用walk_recursion来计算当前方格向下或向右能得到的金币总数
    */
    if(i>=n-1 && j>=n-1){
        //返回方格右下角
        return coins[n-1][n-1];
    }else if(state[i][j]==-1){
        //如果该格子还未被访问过
        if(i<n && j<n){
            //在方格范围内
            //分别计算向下和向右一格能得到的金币总数
            int rout_1=coins[i][j]+walk_recursion(coins, i+1, j);
            int rout_2=coins[i][j]+walk_recursion(coins, i, j+1);
            //把两条路径中金币数多的一条存入state
            state[i][j]=max(rout_1, rout_2);
            //返回该点能拿到的最多金币
            return max(rout_1, rout_2);
        }else{
            //不在方格范围呢，返回0
            return 0;
        }
    }else{
        //如果该格子已经被访问，则直接取出该格子能拿到最多的金币数量
        return state[i][j];
    }
}

int dp(int coins[][1000]){
    /*
        动态规划：因为每个格子的上一步只能从上方或者左边走过来，所以动态方程应该是
        coins[i-1][j], coins[i][j-1]中的最大值。但要注意首行与首列元素只能从本行，列
        的上一个元素走来，所以先计算首行与首列元素的值。
    */
    for(int i=1; i<n; i++){
        //计算首行/列的值
        coins[i][0]+=coins[i-1][0];
        coins[0][i]+=coins[0][i-1];
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            //计算当前格子所能拿到金币的最大值
            coins[i][j]+=max(coins[i-1][j], coins[i][j-1]);
        }
    }
    return coins[n-1][n-1];
}


int main(){
    cin>>n;
    int coins_copy[1000][1000];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>coins[i][j];
            state[i][j]=-1;
        }
    }
    memcpy(coins_copy, coins, sizeof(coins)/sizeof(coins[0][0])*sizeof(int));
    cout<<walk_recursion(coins, 0, 0)<<endl;
    cout<<dp(coins_copy)<<endl;
    return 0;
}
