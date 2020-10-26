#include <vector>
using namespace std;
//暴力解法
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for(int i =0;i < n;++i){
            int res = 0;
            for(int j = 0;j < n;++j){
                if(nums[j] < nums[i]){
                    ++res;
                }
            }
            result.push_back(res);
        }
        return result;
    }
};

//排序加映射
#include <algorithm>
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums){
        vector<pair<int,int>> help;
        int n = nums.size();
        for(int i = 0;i < n;++i){
            help.push_back({nums[i],i});
        }
        sort(help.begin(),help.end());
        vector<int> res(n,0);
        //记录前面有几个数
        int pre = -1; 
        for(int i = 0;i < n;++i){
            //首次和符合条件时赋值
            if(pre == -1 || help[i].first != help[i-1].first){
                pre = i;
            }
            res[help[i].second] = pre;
        }
        return res;
    }
};

//计数排序
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101, 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }
        for (int i = 1; i <= 100; i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            ret.push_back(nums[i] == 0 ? 0: cnt[nums[i]-1]);
        }
        return ret;
    }
};
