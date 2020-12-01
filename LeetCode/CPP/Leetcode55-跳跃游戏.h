#pragma once
#include <vector>
#include <algorithm>
using namespace std;
//找范围的贪心，只要范围能覆盖，就能跳到，不要关心是怎么跳到的
class Solution {
public:
    bool canJump(vector<int>& nums){
        if(nums.size() == 0){
            return false;
        }
        int index = 0;
        //在覆盖的范围里更新最大范围
        for(int i = 0;i <= index;++i){
            index = max(index,i + nums[i]);
            if(index >= nums.size() - 1){
                return true;
            }
        }
        return false;
    }
};

//动态规划，会超时
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
