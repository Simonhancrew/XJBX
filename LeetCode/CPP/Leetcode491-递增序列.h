#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;
class Solution {
public:
    //DFS加回溯
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subsequense;
        DFS(nums,result,subsequense,0);
        return result;
    }
private:
    void DFS(const vector<int> &nums,vector<vector<int>> &result,vector<int> &subsequense,int startIndex){
        unordered_set<int> used;
        if(subsequense.size()>1){
            result.push_back(subsequense);
        }
        for(int i = startIndex;i<nums.size();i++){
            if((subsequense.empty()||nums[i]>=subsequense.back())&&used.find(nums[i])==used.end()){
                subsequense.push_back(nums[i]);
                DFS(nums,result,subsequense,i+1);
                subsequense.pop_back();
                used.insert(nums[i]);
            }
        }
    }
};
class Solution2 {
public:
    // 判重代码；
    bool is_first(const vector<int> &num, int last, int pos) {
        for(int i = last+1; i < pos; i++) {
            if(num[i] == num[pos]) {
                return false;
            }
        }
        return true;
    }
    void dfs(const vector<int> &nums, int last, int pos, vector<int> &stack, vector<vector<int>> &anw) {
        if(nums.size() == pos) { return; } //到达末尾，直接返回吧
        // 检查 nums[pos] 是否符合要求
        if((stack.empty() || nums[pos] >= stack.back()) && is_first(nums, last, pos)) {
            stack.push_back(nums[pos]);
            if(stack.size() >= 2) { //大于 2 了，那就放进去吧
                anw.push_back(stack);
            } 
            dfs(nums, pos, pos+1, stack, anw); // 继续处理下一个。
            stack.pop_back(); // 将当前放入这个吐出来。
        }
        dfs(nums, last, pos+1, stack, anw);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> anw;
        vector<int> stack;
        dfs(nums, -1, 0, stack, anw);
        return anw;
    }
};