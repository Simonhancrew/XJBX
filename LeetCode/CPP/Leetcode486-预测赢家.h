#include <vector>
using namespace std;
//玩家和之差大于等于0则1胜利
//从start开始到end结束去递归。从两个位置各选一次，当前玩家选择最大的结果
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return total(nums, 0, nums.size() - 1, 1) >= 0;
    }

    int total(vector<int>& nums, int start, int end, int turn) {
        if (start == end) {
            return nums[start] * turn;
        }
        int scoreStart = nums[start] * turn + total(nums, start + 1, end, -turn);
        int scoreEnd = nums[end] * turn + total(nums, start, end - 1, -turn);
        return max(scoreStart * turn, scoreEnd * turn) * turn;//？
    }
};