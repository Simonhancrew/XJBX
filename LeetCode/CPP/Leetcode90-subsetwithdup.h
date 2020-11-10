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

#include <algorithm>
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        path.clear();
        res.clear();
        backtrack(nums,0,used);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int> &nums,int startIndex,vector<bool> &used){
        res.push_back(path);
        for(int i = startIndex;i<nums.size();++i){
            //同之前子集一样，看层是否重复。used是ture的话说明在枝上用过，可以继续使用
            if(i > 0 && nums[i-1] == nums[i] && used[i-1] == false){
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums,i+1,used);
            used[i] = false;
            path.pop_back();
        }
    }
};