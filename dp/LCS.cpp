/*
Title: Longest Common Subsequence
Author: daniel wang
*/
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 声明dp数组
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size()+1, 0));
        //i代表text1的索引，j代表text2的索引，dp[i][j]代表当前位置的最大相等数
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                //如果有相同字符，则在上一次的基础上加1
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else {
                    //否则在上方和左侧的值中选一个最大的
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                cout<<dp[i][j];
            }
            cout<<endl;
        }
        return dp[text1.size()][text2.size()];
    }
};

int main() {
    Solution res;
    string text1 = "ABCBDAB";
    string text2 = "BDCABA";
    cout<<res.longestCommonSubsequence(text1,text2)<<endl;
}