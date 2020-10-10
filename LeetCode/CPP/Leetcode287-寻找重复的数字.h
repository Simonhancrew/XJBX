#include <vector>
using namespace std;
//1 一个很精彩的方法，floyd圈
//因为有重复的数，构建图的话,一定有环，找到这个环的入口就行了。i->nums[i]
class Solution {
public:
    int findDuplicate(vector<int> &nums){
        int slow = 0,fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

//2 二分查找
//1-n,有重复的数字target,则重复的数字占用了未来不重复数字的位置，在[0,taget-1],cnt[i]表示小于等于i的数字有多少个，cnt[i]<=i.在[target+1,n]中cnt[i]>i
//有序的是从1到n的数，不是数组中的元素，我们要找到这个1-n中的数
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += nums[i] <= mid;
            }
            if (cnt <= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};