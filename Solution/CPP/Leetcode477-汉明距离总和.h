#include <vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0;i < 30;i++){
            int c = 0;
            for(auto num:nums){
                if((num >> i) & 1) c++;
            }
            res += c * (n - c);
        }
        return res;
    }
};