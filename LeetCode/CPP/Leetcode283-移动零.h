#include <vector>
using namespace std;
//移动删除，朴实无华双指针。
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j = 0;j < nums.size();++i,++j){
            while(nums[j] == 0 && j+1 < nums.size()){
                ++j;
            }
            nums[i] = nums[j];
        }
        while(i < nums.size()){
            nums[i] = 0;
            ++i;
        }
    }
};