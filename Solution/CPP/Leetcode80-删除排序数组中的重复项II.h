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

//unique,更优雅的写法，k指向新数组的末尾，只要新的元素不等于nums[k-1]和nums[k]就可以插入
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        int k = 1;
        for(int i = 2;i < nums.size();i++){
            if(nums[i] != nums[k - 1]){
                nums[++k] = nums[i];
            }
        }
        return k+1;
    }
};