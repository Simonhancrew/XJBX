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