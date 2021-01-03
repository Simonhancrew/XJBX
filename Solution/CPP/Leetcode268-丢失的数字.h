#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        for(int i = 0;i < n;++i){
            res = res ^ i ^ nums[i]; 
        }
        return res;
    }
};