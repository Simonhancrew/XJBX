#include <vector>

using namespace std;


// 双指针
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res = 0,n = nums.size();
        int sum = 0;
        int r = 0,l1 = 0,l2 = 0;
        int s1 = 0,s2 = 0;
        while(r < n){
            s1 += nums[r];
            while(l1 <= r && s1 > goal) s1 -= nums[l1++];
            s2 += nums[r];
            while(l2 <= r && s2 >= goal) s2 -= nums[l2++];
            res += l2 - l1;
            r++;
        }
        return res;
    }
};


// 前缀和
#include <unordered_map>

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> cnt;
        int res = 0;
        int sum = 0;
        for(auto& num:nums){
            cnt[sum]++;
            sum += num;
            res += cnt[sum - goal];
        }
        return res;
    }
};