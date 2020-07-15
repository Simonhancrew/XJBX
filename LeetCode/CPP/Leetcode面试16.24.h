#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 2){
            return res;
        }
        unordered_map<int, int> mp; 
        for (auto i:nums)
        {
            ++mp[i];
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            auto iter = mp.find(nums[i]);
            if (iter != mp.end() && iter->second > 0)
            {
                auto iter1 = mp.find(target - nums[i]);
                if (iter1 != mp.end() && iter1->second > 0)
                {
                    if (iter->first == iter1->first && iter1->second == 1)
                    {
                        continue;//同一个数如果只出现一次的情况12-6=6
                    }
                    res.push_back(vector<int>{iter->first, iter1->first});
                    --iter1->second; //次数减一
                    --iter->second; //次数减一
                }
            }
        }
        return res;
    }
};