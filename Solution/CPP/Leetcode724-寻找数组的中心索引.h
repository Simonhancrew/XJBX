#include <vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return -1;
        }
        int totalsum = 0;
        for(int num:nums){
            totalsum += num;
        }
        int sum = 0;
        for(int i = 0;i < n;i++){
            if(sum == totalsum - nums[i] - sum){
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};