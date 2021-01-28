#include <vector>
using namespace std;
//count记录数的重复次数
//ptr往前推进,count合格的时候才进
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int ptr = 1;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == nums[i-1]){
                count++;
            }else{
                count = 1;
            }

            if(count<=2){
                nums[ptr] = nums[i];
                ptr++;
            }
        }
        nums.resize(ptr);
        return ptr;
    }
};