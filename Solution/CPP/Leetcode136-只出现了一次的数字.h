//要求线性时间复杂度，还不能使用额外的空间
//哈希表就不能使用了，只出现一次？->某一个出现了奇数次，其余偶数次
//异或啊
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1;i < nums.size();++i){
            res ^= nums[i];
        }
        return res;
    }
};