/* ************************************************************************
> File Name:     binary_search.cpp
> Author:        Daniel Wang
> Mail:          Herrwangistcool@foxmail.com
> Created Time:  Sun Feb 27 15:23:57 2022
> Description:   
 ************************************************************************/

#include<vector>
#include<iostream>
using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target){
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int middle=left+((right-left)/2);
            if(nums[middle]>target){
                right=middle-1;
            }else if(nums[middle]<target){
                left=middle+1;
            }else{
                return middle;
            }
        }
        return -1;
    }
};

int main(){
    Solution Solution1;
    vector<int>nums;
    for(int i=1; i<10; i++){
        nums.push_back(i);
    }
    int target=5;
    cout<<Solution1.search(nums,target)<<endl;
    return 0;
}
