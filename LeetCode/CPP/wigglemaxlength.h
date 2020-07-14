//摇摆最长序列
class Solution {

//利用自动状态机的思想，三个状态，只有在状态转换的时候选择length++。贪心的选择上升或是下降的峰值和谷值。
public:
    int wiggleMaxLength(vector<int>& nums) {
        static const int begin = 0;
        static const int up = 1;
        static const int down = 2;
        if (nums.size()<2){
            return nums.size();
        }
        int STATE = begin;
        int maxlength =  1;
        for (auto i = 1;i<nums.size();i++){
            switch(STATE){
                case begin:
                if (nums[i-1]<nums[i]){
                    STATE = up;
                    maxlength++;
                }else if (nums[i-1]>nums[i]){
                    STATE = down;
                    maxlength++;
                }else{
                    STATE = begin;
                }
                break;
                case up:
                if (nums[i-1]>nums[i]){
                    STATE = down;
                    maxlength++;
                }
                break;
                case down:
                if (nums[i-1]<nums[i]){
                    STATE = up;
                    maxlength++;
                }
                break;
            }
        }
        return maxlength;

    }
};