#include <vector>
#include <algorithm>
using namespace std;
//双指针，用哈希需要判断太多东西。数组已经有序
//i遍历，left = i+1,right = end
//收缩lhs和rhs，找到的时候push入result，继续收缩lhs和rhs，直到两边重叠
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            //有序之后的，要处理的剩下的部分的第一个数都大于零的话，和一定不可能等于0
            if(nums[i] > 0){
                return result;
            }
            //第一个去重方法要注意考虑  -1，-1，2
            //下一个元素和已经处理的元素一样的话可以不处理了
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = nums.size()-1;
            while(right >left){
                //0 0 0 ?
                if(nums[i]+nums[left]+nums[right]>0){
                    right--;
                }else if (nums[i]+nums[left]+nums[right]<0){
                    left++;
                }else{
                    result.push_back(vector<int> {nums[i],nums[left],nums[right]});
                    //第二个去重，这个一定存在了，在本次循环中没必要考虑了
                    while(right > left && nums[right] == nums[right-1]) right--;
                    while(right > left && nums[left] == nums[left+1]) left++;
                    //找到答案收缩两个指针
                    right--;
                    left++;
                }
            }
        }
        return result;
    }   
};