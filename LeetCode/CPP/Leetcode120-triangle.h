#pragma once
#include<vector>
#include<algorithm>
//三角形最短路径和，leetcode 120
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        if (triangle.size() == 0) {
            return 0;
        }
        for (int i = 0; i < triangle.size(); i++) {
            dp.push_back(vector<int>());
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[i].push_back(0);
            }
        }
        for (int i = 0; i < dp[dp.size()-1].size(); i++) {
            dp[dp.size() - 1][i] = triangle[dp.size() - 1][i];
        }
        for (int i = dp.size() - 2; i >= 0; i--) {
            for (int j = 0; j < dp[i].size(); j++) {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};