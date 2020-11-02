#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> index;
        for (auto i = 0; i < nums.size(); i++) {
            index.push_back(i + nums[i]);
        }
        int jump = 0;
        int max_index = index[0];
        while (jump <= max_index && jump < index.size()) {
            max_index = max(index[jump], max_index);
            jump++;
        }
        if (jump == index.size()) {
            return true;
        }
        return false;
    }
};
//动态规划
//最后一步，假设能跳到
//回到之前的一步
class Solution {
public:
    bool canJump(vector<int>& nums){
        if(nums.size() == 0){
            return false;
        }
        vector<bool> dp;
        for(int i =0;i<nums.size();++i){
            dp.push_back(false);
        }
        dp[0] = true;
        //对于之后的数
        for(int j = 1;j<nums.size();j++){
            //如果之前有数能跳到
            for(int i =0;i < j;++i){
                if(dp[i] && i+nums[i] >= j){
                    dp[j] = true;
                    break;
                }
            }
        }
        return dp[nums.size() - 1];
    }
};
