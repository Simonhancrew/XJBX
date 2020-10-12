#include <vector>
#include <algorithm>
using namespace std;
//排序加全搜
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(i>0 && nums[i-1] == nums[i]){
                continue;
            }
            for(int j = i+1;j<n;++j){
                if(j>i+1 && nums[j-1] == nums[j]){
                    continue;
                }
                if(abs(nums[i] - nums[j]) == k){
                    ++res;
                }
            }
        }
        return res;
    }
};

//排序加快慢指针
class Solution{
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = 1;
        while (right < nums.size()) {
            int diff = nums[right] - nums[left];
            if (diff == k) {
                count++;
                //去重
                while (right < nums.size() - 1 && nums[right + 1] == nums[right]) {
                    right++;
                }
                while (left < right && nums[left + 1] == nums[left]) {
                    left++;
                }
                left++;
                //右边是否要处理
                do {
                    right++;
                } while (left >= right);
            } else if (diff > k) {//大了移左边
                left++;
                //超过了右边吗？
                if (left >= right) {
                right++;
                }
            } else {//小了移右边
                right++;
            }
        }
    return count;
    }
};

//哈希
#include <set>
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
        return 0;
        // 保存访问的元素
        std::set<int> saw;
        // 保存 k-diff 数对中较小的那个（也可以保存较大的）只用来统计数对个数
        std::set<int> diff;

        for (int i = 0; i < nums.size(); i++) {
            //diff只插入一种数
            // 检查数对中较小的数 1 是否在数组中：3 - 2 = 1
            if (saw.find(nums[i] - k) != saw.end())
                diff.insert(nums[i] - k); // 插入数对中较小的数 1
            // 检查数对中较大的数 3 是否在数组中：1 + 2 = 3
            if (saw.find(nums[i] + k) != saw.end())
                diff.insert(nums[i]); // 插入数对中较小的数 1
            saw.insert(nums[i]);
        }
        // 因为 set 中不存在重复元素，所以不同的元素个数代表不同的 k-diff 数对个数
        return diff.size();
    }
};