#include <vector>
using namespace std;
//单指针
//荷兰国旗
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int ptr = 0;
        //0到头部
        for(int i =0;i<size;++i){
            if(nums[i] == 0){
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
        //1到第二部分
        for(int i = ptr;i<size;i++){
            if(nums[i] == 1){
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
        //剩下全为2
    }
};

//双指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                ++p1;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
    }
};