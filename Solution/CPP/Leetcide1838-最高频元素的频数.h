#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res = 1,n =  nums.size();
        typedef long long LL;
        LL need = 0;
        for(int l = 0,r = 1;r < n;r++){
            need += (LL)(r - l) * (nums[r] - nums[r - 1]);
            while(need > k){
                need -= (nums[r] - nums[l]);
                l++;
            }
            res = max(res,r - l + 1);
        }
        return res;
    }
};