#include <vector>
using namespace std;
//要求就地删除，考虑双指针的方法
//否则的话第一想法是利用栈
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fast = 0,slow = 0;
        if(nums.size() == 0){
            return 0;
        }
        while(fast<nums.size()){
            if(nums[fast] == nums[slow]){
                ++fast;
            }else{
                slow++;
                swap(nums[slow],nums[fast]);
                fast++;
            }
        }
        nums.resize(slow+1);
        return slow+1;
    }
};