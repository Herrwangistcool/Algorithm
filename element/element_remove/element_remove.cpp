/* ************************************************************************
> File Name:     element_remove.cpp
> Author:        Daniel Wang
> Mail:          Herrwangistcool@foxmail.com
> Created Time:  Sat Mar  5 16:02:54 2022
> Description:   给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

                 不要使用额外的数组空间，你必须仅使用 $O(1)$ 额外空间并原地修改输入数组。

                 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

                 示例 1: 给定 nums = [3,2,2,3], val = 3, 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。 你不需要考虑数组中超出新长度后面的元素。

                 示例 2: 给定 nums = [0,1,2,2,3,0,4,2], val = 2, 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。 
 ************************************************************************/
#include<vector>
#include<iostream>
using namespace std;

class Solution{
public:
    int removeElement_default(vector<int>& nums, int val){
        int size=nums.size();
        for(int i=0; i<size; i++){
            if(nums[i]==val){
                for(int j=i+1; j<size; j++){
                    nums[j-1]=nums[j];
                }
                i--;    //因为此时下标i的数值已经变成后面一位数，所以i也要向前移动一步
                size--; //数组长度减1
            }
        }
        return size;
    }
    //快慢指针法
    int removeElement_2Indexes(vector<int>& nums, int val){
        int slowIndex=0;    //定义慢指针
        for(int fastIndex=0; fastIndex<nums.size(); fastIndex++){
            if(val!=nums[fastIndex]){   //如果当前fastIndex所在的值不等于指定的val，则将fastIndex所在的值赋给slowIndex
                nums[slowIndex++]=nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main(){
    Solution example;
    vector<int>list;
    for(int i=0; i<=5; i++){
        list.push_back(i);
    }
    // int size=example.removeElement_default(list,1);
    int size=example.removeElement_2Indexes(list,1);
    cout<<size<<endl;
    for(int i=0; i<size; i++){
        cout<<list.at(i)<<' ';
    }
    cout<<endl;
    return 0;
}
