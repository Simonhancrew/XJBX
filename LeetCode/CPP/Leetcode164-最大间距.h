#include <vector>
#include <algorithm>
using namespace std;
//最朴素的思路
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }
        int ret = INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i = 1;i < nums.size();++i){
            ret = max(nums[i] - nums[i-1],ret);
        }
        return ret;
    }
};

//基数排序和桶排序
//相邻数之间的最大间距不会小于max-min/n-1
//因为可能有相等的，则分d个桶，桶内间距可能很小
//d = max-min/n-1.最大的间距一定在两桶之间
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int d = max(1, (maxVal - minVal) / (n - 1));
        int bucketSize = (maxVal - minVal) / d + 1;

        vector<pair<int, int>> bucket(bucketSize, {-1, -1});  // 存储 (桶内最小值，桶内最大值) 对，(-1, -1) 表示该桶是空的
        for (int i = 0; i < n; i++) {
            int idx = (nums[i] - minVal) / d;
            if (bucket[idx].first == -1) {
                bucket[idx].first = bucket[idx].second = nums[i];
            } else {
                bucket[idx].first = min(bucket[idx].first, nums[i]);
                bucket[idx].second = max(bucket[idx].second, nums[i]);
            }
        }

        int ret = 0;
        int prev = -1;
        for (int i = 0; i < bucketSize; i++) {
            if (bucket[i].first == -1) continue;
            if (prev != -1) {
                ret = max(ret, bucket[i].first - bucket[prev].second);
            }
            prev = i;
        }
        return ret;
    }
};