#include <vector>
using namespace std;
class Solution {
public:
    int result = 1;
    void calcu(vector<int> nums,int n){
        vector<int> dp(n,1);
        for(int i = 0;i < n;++i){
            if(i > 0 && nums[i-1] < nums[i]){
                dp[i] = dp[i-1] + 1;
            }
            result = max(result,dp[i]);
        }
        
    } 
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        calcu(nums,n);
        // int i = 0,j = nums.size() - 1;
        // while(i < j){
        //     auto tmp = nums[i];
        //     nums[i] = nums[j];
        //     nums[j] = tmp; 
        // }
        // calcu(nums,n);
        return result;
    }
};