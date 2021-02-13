#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(auto num:nums){
            //之前可能已经被加过了
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> ans;
        for(int i = 0;i < n;i++){
            if(nums[i] <= n){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};