#pragma once
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> item;
        vector<vector<int>> result;
        set<vector<int>> res_set;
        sort(nums.begin(), nums.end());
        result.push_back(item);
        generate(0, nums, item, result, res_set);
        return result;
    }
private:
    void generate(int i, vector<int> &nums, vector<int> &item, vector<vector<int>> &result, set<vector<int>> &res_set) {
        if (i >= nums.size()) {
            return;
        }
        item.push_back(nums[i]);
        if (res_set.find(item) == res_set.end()) {
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i + 1, nums, item, result, res_set);
        item.pop_back();
        generate(i + 1, nums, item, result, res_set);

    }
};