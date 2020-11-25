//摇摆最长序列
#include <vector>
using namespace std;
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

//其实可以看成是一个山峰数组，峰值必须是连续得
//但给出得数组可能不是连续得，就要你求出连续得话是多长
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int curdiff = 0;
        int prediff = 0;
        int ret = 1;//开头一定就是一个山峰或者山谷（整体是可以删的）
        for(int i = 1;i < nums.size();++i){
            curdiff = nums[i] - nums[i - 1];
            //前半部分找山峰，cur前后必须有正差值，pre前后如果是减小的，之前就是山谷值，如果等0，也可以找到山峰
            //后半部分找山谷，cur前后必须有负差值。pre前后如果是增加的，之前便是山峰，如果是0，cur也可以找到山谷
            //cur必须明确增
            if((curdiff > 0 && prediff <= 0)||(curdiff < 0 && prediff >= 0)){
                ret++;
                prediff = curdiff;
            }
        }
        return ret;
    }
};