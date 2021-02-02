#include <string>
using namespace std;
//我们只要一个区间大小的值
//所以可以枚举每一个右端点，找到他的左边最远的端点
//对此，我们持续维持最大的区间长度
//虽然最后有些区间会不符合要求，但是这些不会造成区间长度的贡献
//然后对于每个不符合区间，我们移动左端点一位，防止其后续造成贡献
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        //记录当前这个区间中，每个字母有多少个
        int nums[26];
        for(int &num:nums){
            num = 0;
        }
        //最多的字符
        int maxn = 0;
        int fast = 0,slow = 0;
        while(fast < n){
            //右边字符+1
            nums[s[fast] - 'A']++;
            //确定最多的字符
            maxn = max(maxn,nums[s[fast] - 'A']);
            //不符合条件就左端点右移一位
            if(fast - slow + 1 - maxn > k){
                nums[s[slow] - 'A']--;
                slow++;
            }
            fast++;
        }
        //最后这个区间的长度一定是答案
        return fast - slow;
    }
};