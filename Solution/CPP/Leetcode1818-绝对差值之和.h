#include <vector>
#include <algorithm>

using namespace std;

// 首先算一遍初始值，遍历1-n，找到nums1中距离nums2最近的一个值，替换试试看。
// 这里最快的找到可以考虑二分，需要额外数组排序，总共nlogn的时间复杂度

class Solution {
public:
    const int MOD = 1e9 + 7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> t(nums1);
        sort(t.begin(),t.end());
        int n = nums1.size();
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum = (sum + abs(nums1[i] - nums2[i])) % MOD;
        }
        int res = sum;
        for(int i = 0;i < n;i++){
            int l = 0,r = n - 1;
            while(l < r){
                int mid = l + r >> 1;
                if(nums2[i] <= t[mid]) r = mid;
                else l = mid + 1;
            }
            res = min(res,sum - abs(nums1[i] - nums2[i]) + abs(t[l] - nums2[i]));
            if(l > 0){
                res = min(res,sum - abs(nums1[i] - nums2[i]) + abs(t[l - 1] - nums2[i]));
            }
        }
        return (res + MOD) % MOD;
    }
};