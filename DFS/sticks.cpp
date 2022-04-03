/* ************************************************************************
> File Name:     sticks.cpp
> Author:        Daniel Wang
> mail:          herrwangistcool@foxmail.com
> Created Time:  Mon Apr  4 00:42:11 2022
> Description:   有N根木棍，需要将其粘贴成M个长木棍，使得最长的和最短的的差距最小。
输入格式
　　第一行两个整数N,M。
　　一行N个整数，表示木棍的长度。
输出格式
　　一行一个整数，表示最小的差距
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define MAX 9999
#define MIN -9999

const int maxn=10;
int lens[maxn];
int n, m, d;

void DFS(int k){
    if(k==m){
        int maxL=MIN;
        int minL=MAX;
        for(int i=0; i<k; i++){
            //找出当前方案的最大与最小值
            if(lens[i]<minL)    minL=lens[i];
            if(lens[i]>maxL)    maxL=lens[i];
        }
        d=min(d, maxL-minL);
        return;
    }
    for(int i=0; i<k; i++){
        for(int j=i+1; j<k; j++){
            //每次取出两个木棍，将他们的值相加
            lens[i]+=lens[j];
            //交换被加的木棍长度与数组尾部的值
            swap(lens[j], lens[k-1]);
            //对前k-1个木棍长度进行深度搜索
            DFS(k-1);
            //恢复到上一个状态
            swap(lens[j], lens[k-1]);
            lens[i]-=lens[j];
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>lens[i];
    }
    d=MAX;
    DFS(n);
    cout<<d<<endl;
    return 0;
}
