#include <vector>
using namespace std;
//过不去oj
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        for(int i = 0;i < nums.size();++i){
            int sum = 0;
            for(int j = i;j < nums.size();++j){
                sum += nums[j];
                if(sum == k){
                    res++;
                }
            }
        }
        return res;
    }
};


//前缀和，序列连续，找到和为k的序列可以选择-
//以i结尾的序列是否有连续子数组和为k
//往前找一个坐标j，j-> i的和是为k,则前面0-j的和在序列中已经求出来了
//这个自由度下，这几者是相关的
#include <unordered_map>
class Solution{
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int pre = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int n = nums.size();
        for(int i = 0;i < n;++i){
            pre += nums[i];
            if(mp.find(pre - k) != mp.end()){
                res += mp[pre - k];
            }
            mp[pre]++;
        }
        return res;
    }
};