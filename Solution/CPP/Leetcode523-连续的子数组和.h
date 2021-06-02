#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) return false;
        unordered_map<int,int> hash;
        hash[0] = -1;
        int re = 0;
        for(int i = 0;i < n;i++){
            re = (re + nums[i]) % k;
            if(hash.count(re)){
                int idx = hash[re];
                if(i - idx >= 2) return true;
            }else{
                hash[re] = i;
            }
        }
        return false;
    }
};