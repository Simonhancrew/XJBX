#pragma once
#include<vector>
//最大上升序列，leetcode 300
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int Lis = 1;
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (Lis < dp[i]) {
                Lis = dp[i];
            }
        }
        return Lis;
    }
};
/*
贪心的选择上升速度最小，d[i]为当前位置为结尾的最小可能数
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) return 0;
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) d[++len] = nums[i];
            else{
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
*/