#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        int start = 0,end = nums.size() - 1;
        while(start <= end){
            //不要让mid溢出int
            int mid = start + (end - start) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        } 
        return -1;
    }
};