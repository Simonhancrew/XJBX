#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<int> exist(nums.size(),0);
        backtracking(nums, result, current, exist);
        return result;
    } 
private:
    void backtracking(vector<int>& nums,vector<vector<int>> &result,vector<int> current,vector<int> &exist) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        int n = nums.size();
        for (int i = 0; i < n;i++) {
            if (exist[i] == 1) {
                continue;
            }
            else
            {
                current.push_back(nums[i]);
                exist[i] = 1;
                backtracking(nums, result, current, exist);
                exist[i] = 0;
                current.pop_back();
            }
        }
    }
};