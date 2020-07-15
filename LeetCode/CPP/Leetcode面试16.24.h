class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {

        vector<vector<int>> res;

        if (nums.size() < 2)
        {
            return res;
        }

        unordered_map<int, int> mp; // <值，次数>
        for (int i = 0; i < nums.size(); ++i)
        {
            ++mp[nums.at(i)];
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            auto iter = mp.find(nums.at(i));
            if (iter != mp.end() && iter->second > 0)
            {
                auto iter1 = mp.find(target - nums.at(i));
                if (iter1 != mp.end() && iter1->second > 0)
                {
                    if (iter->first == iter1->first && iter1->second == 1) //不能是同一个数
                    {
                        continue;
                    }
                    res.push_back(vector<int>{iter->first, iter1->first});
                    --iter1->second; //次数减一
                }

                --iter->second; //次数减一
            }
        }

        return res;
    }
};