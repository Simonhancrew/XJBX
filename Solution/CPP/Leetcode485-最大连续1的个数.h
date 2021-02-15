#include <vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int start = 0,end = 0;
        while(end < n){
            if(nums[end] == 1){
                ans = max(ans,end -start + 1);
                end++;
            }else{
                start = end + 1;
                end = start;
            }
        }
        return ans;
    }
};