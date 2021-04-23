#include <vector>
#include <algorithm>

//整除具有传递性。
//考虑最后一步，之前状态最优，他之前可以取的数就之前能被他整除的数
//对这些状态取一个max+1就可以了

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        sort(nums.begin(),nums.end());
        int k = 0;
        for(int i = 0;i < n;i++){
            dp[i] = 1;
            for(int j = 0;j < i;j++){
                if(nums[i] % nums[j] == 0){
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
            if(dp[i] > dp[k]) k = i;
        }
        vector<int> res;
        while(true){
            res.push_back(nums[k]);
            if(dp[k] == 1){
                break;
            }
            for(int i = 0;i < k;i++){
                if(nums[k] % nums[i] == 0 && dp[i] + 1 == dp[k]){
                    k = i;
                    break;
                }
            }
        }
        return res;
    }
};