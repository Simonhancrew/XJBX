#include <vector>
#include <unordered_map>
using namespace std;
//哈希表
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int res = -1;
        for(auto num:nums){
            mp[num]++;
            if(mp[num] > nums.size()/2){
                res = num;
            }
        }
        return res;
    }
};

//摩尔投票计数法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = nums[0],count = 1;
        for(int i = 1;i < nums.size();++i){
            if(count == 0){
                cur = nums[i];
                count = 1;
            }else if(nums[i] == cur){
                ++count;
            }else{
                --count;
            }
        }
        return cur;
    }
};