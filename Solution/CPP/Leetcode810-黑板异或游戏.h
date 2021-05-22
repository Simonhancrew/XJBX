#include <vector>

//先手必败，无论怎么走都是必胜态
//先手必胜，有一种方法走到必败态
//简单博弈论。要么开始直接就是胜态，要么开始的长度是偶数，因为是偶数的时候总能找到一种异或方法走到必败态
//反证，假设开始的异或和不为0，假设去任意一个点i之后等于0，记这个和为si，然后将所有的si异或上，分解之后不难得到偶数个s的异或和全部num的异或
//最后的结果就是 s = 0,这和开始的假设冲突了

using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int res = 0;
        for(auto num:nums){
            res ^= num;
        }
        return !res || nums.size() % 2 == 0;
    }
};