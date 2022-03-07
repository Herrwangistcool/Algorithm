/* ************************************************************************
> File Name:     water_store.cpp
> Author:        Daniel Wang
> Mail:          Herrwangistcool@foxmail.com
> Created Time:  Mon Mar  7 18:58:16 2022
> Description:   盛水问题
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
输入：nums = [0,1,0,2,1,0,1,3,2,1,2,1]，输出：6。
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水） 
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int water_store(vector<int>& nums){
        /*
         大体思路：找出数组中最高点的下标，记为maxPositon，以maxPosition为界
         将数组一分为二。设立两个下标，分别从数组的左右两边向中间靠拢。
         */
       int size=nums.size();    //获取数组长度
       int water_volumn=0;      //初始化雨水的体积
       int maxPosition = max_element(nums.begin(),nums.end()) - nums.begin();
       for(int left=0, height=nums[0]; left<maxPosition; left++){
           //从数组最左侧向中间遍历
           if(nums[left]>height){
               //如果当前下标的值大于先前最高的值，则将新的高度值赋给height
               height=nums[left];
           }else{
               //height减去比其矮的值，直到下一次碰到比当前高度高的下标
               water_volumn+=height-nums[left];
           }
       }
       for(int right=size-1, height=nums[size-1]; right>maxPosition; right--){
           //从数组最右侧向中间遍历
           if(nums[right]>height){
               height=nums[right];
           }else{
               water_volumn+=height-nums[right];
           }
       }
       //while(slow_point<size){
       //    /*
       //     思路：设置一快一慢两个指针，当快指针所处位置的值大于或等于慢指针时， 
       //     用慢指针所处的值与在快慢指针中间的值做差，将每次的差求和得到水的体积
       //    */
       //    int status=1;    //status用于调整慢指针移动
       //    for(fast_point=slow_point+1; fast_point<size; fast_point++){
       //        if(nums[fast_point]>=nums[slow_point]){
       //            //快指针所处位置的值大于或等于慢指针
       //            status=0;    
       //            for(int i=slow_point; i<fast_point; i++){
       //                //将慢指针所在位置的值与快慢指针中间的值做差并求和
       //                water_volumn+=nums[slow_point]-nums[i];
       //            }
       //            break;
       //        }
       //    }
       //    if(status){
       //        //如果status为1，则慢指针向前移动一步
       //        slow_point++;
       //    }else{
       //        //如果status为0，则慢指针移动到快指针所在位置
       //        slow_point=fast_point;
       //    }
       //}
       return water_volumn;
    }
};

int main(){
    vector<int> nums {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution example;
    cout<<example.water_store(nums)<<endl;
    return 0;
}
