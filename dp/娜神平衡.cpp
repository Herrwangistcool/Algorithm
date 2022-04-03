/* ************************************************************************
> File Name:     娜神平衡.cpp
> Author:        Daniel Wang
> mail:          herrwangistcool@foxmail.com
> Created Time:  Tue Mar 29 21:15:50 2022
> Description:   娜娜是一个特别可爱的女孩子，作为学神的她最近在情感方面出现了一点点小问题。
她暗恋的琦琦是一名学霸，他只喜欢长得漂亮和学习很好的女生。
娜娜学习确实很神，但是她在琦琦面前却总是表现不出平时的神力。
琦琦感受到了娜娜对他的爱，但是他还是觉得娜娜的学习并不是特别好，于是他出了一道题给娜娜。
“娜娜，我们之间的关系需要在不断深入的同时保持一定的平衡，不可以你总是强势或者我总是弱势。”
琦琦给了娜娜一些两两不等的数，希望娜娜能把这些数分成两组A和B，满足以下条件：
1：每一次只能操作一个数，即只取出一个数分入A中或B中；
2：每一次操作完成后，A中数之和与B中数之和的差不能超过r。
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;  //n个正整数
int r;  //两组数字和只差不能超过r
vector<int> L;  //存放左组数字
vector<int> R;  //存放右组数字

//函数功能：从小到大打印数组
void sortPrint(vector<int> vc){
    sort(vc.begin(), vc.end());
    for(int i=0; i<vc.size(); i++){
        cout<<vc[i]<<" ";
    }
    cout<<endl;
}

//函数功能：左组数字L[], 右组数字R[], 保证两者和只差的绝对值abs(d)<r, 返回是否找到这样的两组数字，并按要求打印
bool check(vector<int> L, vector<int> R, int nums[], bool flag[], int d, int r, int n){
    //两者和只差的绝对值abs(d)>r, 不合题意，回溯
    if(abs(d)>r){
        return 0;
    }

    //全部分完，按要求打印两组数
    if(L.size()+R.size()==n){
        //查找第一个数是否在L中
        int i;
        for(i=0; i<L.size(); i++){
            if(L[i]==nums[0]){
                //在L中，先打印
                sortPrint(L);
                break;
            }
        }
        sortPrint(R);
        //不在L中，先打印R
        if(i==L.size()){
            sortPrint(L);
        }
        return 1;
    }
    int i;
    for(i=0; i<n; i++){
        //如果该数字未被启用，则数字有3种情况
        if(!flag[i]){
            flag[i]=true;   //标记使用

            //1.放L组
            L.push_back(nums[i]);
            //如果符合要求，结束递归
            if(check(L, R, nums, flag, d+nums[i], r, n)){
                break;
            }
            //不符合要求，恢复现场
            L.pop_back();

            //2.放R组
            R.push_back(nums[i]);
            //如果符合要求，结束递归
            if(check(L, R, nums, flag, d-nums[i], r, n)){
                break;
            }
            //不符合要求，恢复现场
            R.pop_back();

            flag[i]=false;

            //3.都不放
        }
    }
    return !(i==n);
}

int main(){
    cin>>n>>r;
    int nums[n];
    bool flag[n]={0};
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    check(L,R,nums,flag,0,r,n);
    return 0;
}
