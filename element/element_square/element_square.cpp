/* ************************************************************************
> File Name:     element_square.cpp
> Author:        Daniel Wang
> Mail:          Herrwangistcool@foxmail.com
> Created Time:  Sat Mar  5 22:43:17 2022
> Description:   给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

                 示例 1： 输入：nums = [-4,-1,0,3,10] 输出：[0,1,9,16,100] 解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]

                 示例 2： 输入：nums = [-7,-3,2,3,11] 输出：[4,9,9,49,121] 
 ************************************************************************/

#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

class Solution{
public:
    vector<int> sortedSquares(vector<int>& list){
        /*
         双指针法：数组是有序的，只不过负数平方后可能成为最大数了。
         那么数组平方的最大值就在数组的两端，不是最左边就是最右边。
         i指向起始位置，j指向终止位置。
         定义一个新数组result，和原数组一样大小，让k指向result的终止位置
         如果list[i]*list[i]<list[j]*list[j]，那么result[k--]=list[j]*list[j];
         如果list[i]*list[i]>list[j]*list[j]，那么result[k--]=list[i]*list[i];
         *
        */
        int k=list.size()-1;
        vector<int> result(list.size(),0);
        for(int i=0, j=list.size()-1;i<=j;){
            //i<=j不能写出i<j，因为最后要处理这两个元素
            if(pow(list[i],2)<pow(list[j],2)){
                result[k--]=pow(list[j],2);
                j--;
            }else{
                result[k--]=pow(list[i],2);
                i++;
            }
        }
        return result;
    }
};

int main(){
    vector<int> list;
    vector<int> copy;
    Solution example;
    int tmp;
    do{
        cin>>tmp;
        list.push_back(tmp);
    }while(getchar()!='\n');
    copy=example.sortedSquares(list);
    for(vector<int>::iterator it=copy.begin(); it!=copy.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
