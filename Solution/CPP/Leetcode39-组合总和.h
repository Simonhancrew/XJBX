#ifndef LEETCODE39
#define LEETCODE39
#include <vector>
#include <algorithm>
using namespace std;
//回溯，从每个位置开始尝试，排序数组是为了加快结束。

//抽象的理解递归，看作黑盒
class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start,int target){
        if(target == 0){
            res.push_back(path);
        }
        for(int i =start;i<candidates.size() && target-candidates[i]>=0;i++){
            path.push_back(candidates[i]);
            DFS(i,target-candidates[i]);//因为确定了可以重复选取，所以回溯的index不需要往前推进
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates = candidates;
        DFS(0,target);
        return res;
    }
};
#endif