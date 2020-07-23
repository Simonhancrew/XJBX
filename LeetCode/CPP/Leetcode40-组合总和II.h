#pragma once
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> item;
        vector<vector<int>> result;
        set<vector<int>> res_set;
        sort(candidates.begin(), candidates.end());
        generate(0, candidates, target, 0, item, result, res_set);
        return result;
    }
private:
    void generate(int i, vector<int>& nums, int target, int sum, vector<int>& item, vector<vector<int>>& result, set<vector<int>>& res_set) {
        if (i >= nums.size() || sum > target) {
            return;
        }
        sum += nums[i];
        item.push_back(nums[i]);
        if (target == sum && res_set.find(item) == res_set.end()) {
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1, nums, target, sum, item, result, res_set);
        item.pop_back();
        sum -= nums[i];
        generate(i+1, nums, target, sum, item, result, res_set);

    }
};