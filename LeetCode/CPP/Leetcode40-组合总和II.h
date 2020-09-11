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

class Solution2 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        //排序以后方便剪枝
        sort(candidates.begin(),candidates.end());
        //构造一下freq,因为已经排序，所以之后出现只可能大于等于
        for(auto i:candidates){
            if(freq.empty()||freq.back().first != i){
                freq.push_back({i,1});
            }else{
                ++freq.back().second;
            }
        }
        DFS(0,target);
        return result;
    }
private:
    //一个去重的hash映射，freq的size就是这个数组有多少不重复的数字
    //之后我们一起处理这些数字，就可以完成即不重复，也不漏掉
    vector<pair<int,int>> freq;
    vector<int> cur;
    vector<vector<int>> result;
    void DFS(int pos ,int target){
        if(target == 0){
            result.push_back(cur);
            return;
        }
        if(pos == freq.size()||target<freq[pos].first){
            return;
        }
        DFS(pos+1,target);
        //为了去除重复的数字，我们递归的一起处理这些数字
        int most = min(target/freq[pos].first,freq[pos].second);
        for(int i = 0;i<most;i++){
            cur.push_back(freq[pos].first);
            DFS(pos+1,target-(i+1)*freq[pos].first);
        }
        for(int i =0;i<most;i++){
            cur.pop_back();
        }
    }
};