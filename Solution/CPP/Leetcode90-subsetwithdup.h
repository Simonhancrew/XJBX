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
            //重新理解一下，就是你用到了相等的可能会重复，这里加一个判断：用到了相等的，且上一个递归层上一定要用过了，这一层才能用这个重复的
            //不然就肯定会导致重复
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


//另一种思路，对于相同的数，先排序，然后统计看有多少个，放0-k个，k是这个数有多少个
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        //不用哈希表统计的话一定要排序
        sort(nums.begin(),nums.end());
        dfs(0,nums);
        return res;
    }
    void dfs(int u,vector<int> &nums){
        if(u == nums.size()){
            res.push_back(path);
            return;
        }
        int k = u;
        //统计看这个数有多少个
        while(k < nums.size() && nums[k] == nums[u]) k++;
        //不放
        dfs(k,nums);
        //放1 - k个
        for(int i = u;i < k;i++){
            path.push_back(nums[i]);
            dfs(k,nums);
        }
        //记得恢复现场
        for(int i = u;i < k;i++){
            path.pop_back();
        }
    }
};