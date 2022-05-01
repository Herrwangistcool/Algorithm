/*
 *@Author: Daniel Wang
 *@Date: 2022-04-24 23:43:22
 *@Description: 0,1背包问题，给定n种物品和一个容量为c的背包，物品i的重量是wi，其价值为vi。
 问：应该如何选择装入背包的物品，使得装入背包中的物品的总价值最大？
*/
#include<iostream>
using namespace std;

int dp[35][205];   //i表示物品，j表示容量，dp表示价值
int w[35],c[35];   //w代表重量数组，c代表价值数组

int main(){
    int m,n;
    cin>>m>>n;
    for(int i=1; i<=n; i++){
        cin>>w[i]>>c[i];
    }
    /*判断拿和不拿*/
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(j<w[i]){ //j不足以放下，此时仍为上一物品的价值
                dp[i][j]=dp[i-1][j];
            }else{
                /*
                两种情况，拿或者不拿，不拿即还是上一物品的价值，
                拿就要将j减去w[i]的重量，找到丢掉上一物品后的价值，再加上当前物品的价值
                */
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
            }
        }
    }
    // 输出dp表
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[n][m];
    return 0;
}
