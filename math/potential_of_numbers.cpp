/* ************************************************************************
> File Name:     hex_to_oct.cpp
> Author:        Daniel Wang
> Mail:          Herrwangistcool@foxmail.com
> Created Time:  Fri Mar 11 00:18:35 2022
> Description:   将一个数N分为多个正整数之和，即N=a1+a2+a3+…+ak，定义M=a1*a2*a3*…*ak为N的潜能。
　　             给定N，求它的潜能M。由于M可能过大，只需求M对5218取模的余数。
 ************************************************************************/
// 这道题是把正整数拆3，变成3+3+3+…，直到这个数小于等于4时；证明链接如下
// https://blog.csdn.net/xiaoquantouer/article/details/70142739
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
//定义快速幂函数
ll poww(ll base, ll power){
    // base底数，power幂
    if(power==1){
        // 如果幂是1，返回底数
        return base;
    }
    if(power==0){
        // 幂为0，返回1
        return 1;
    }
    // (a*b)%p=[(a%p)*(b%p)]%p
    ll square_root=(poww(base, power/2)%5218);
    // flag判断power能否被2整除
    ll flag=power%2;
    if(flag==1){
        // 如果power能被2整除，说明该数能被分为两个平方根，再乘上一个底数
        return ((square_root*square_root*base)%5218);
    }else{
        // 如果power能被2整除，说明该数能正好被分为两个平方根，不用乘底数
        return ((square_root*square_root)%5218);
    }
}

int main(){
    // n输入的值, power幂，remainder余数，sum输出的结果
    ll n, power, remainder, sum=1;
    cin>>n;
    power=n/3;
    remainder=n%3;
    if(remainder==1 && power>0){
        // 如果余数为1且幂大于0，则幂减1，余数加上3得4
        power-=1;
        remainder=4;
    }
    // n分解为power个3，求3的power次快速幂
    sum=poww(3,power);
    if(remainder!=0){
        // 将剩下的余数与sum相乘并取余
        sum*=remainder;
        sum%=5218;
    }
    cout<<sum<<endl;
    return 0;
}
