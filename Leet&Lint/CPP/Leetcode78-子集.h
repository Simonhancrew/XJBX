#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> result;
        backTrack(nums,0,cur,result);
        return result;
    }
private:
    void backTrack(vector<int> &nums,int index,vector<int> cur,vector<vector<int>> &result){
        if(index == nums.size()){
            result.push_back(cur);
            return;
        }
        cur.push_back(nums[index]);
        backTrack(nums,index+1,cur,result);
        cur.pop_back();
    }
};