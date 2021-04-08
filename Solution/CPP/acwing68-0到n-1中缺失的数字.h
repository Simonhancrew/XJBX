#include <vector>
using namespace std;

//满足某种二段性的序列，也是可以使用二分去搜索的
//此题的二段性就在于，缺失的数之前的一段，nums[i] == i

class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] != mid) r = mid;
            else l = mid + 1;
        }
        if(nums[r] == r) r ++;
        return r;
    }
};