#include <vector>
#include <algorithm>
using namespace std;
//和三数值和思路相似
//当我们需要枚举数组中的两个元素时，如果我们发现随着第一个元素的递增，第二个元素是递减的，不如双指针
//多一个循环找第二个数，然后双指针从两边往中间走
//去重的时候要注意，一个数之前一定要找过，之后才能去重
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(nums.size()<4) return res;
        int length = nums.size();
        for(int i =0;i<length-3;i++){
            //去重，注意要已经用过-1,-1,0,2
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            //确定了第一个数之后，连续的还是大于tar，第一层循环结束.不可能存在更小
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target){
                break;
            }
            //如果确定第一个数，之后选三个最大的还是小，本次循环跳过，选下一个第一个数
            if(nums[i]+nums[length-3]+nums[length-2]+nums[length-1]<target){
                continue;
            }
            for(int j = i+1;j<length-2;j++){
                //去重
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target){
                    break;
                }
                if(nums[i]+nums[j]+nums[length-2]+nums[length-1]<target){
                    continue;
                }
                int lhs = j+1,rhs = length-1;
                while(lhs<rhs){
                    int sum = nums[i]+nums[j]+nums[rhs]+nums[lhs];
                    if(sum == target){
                        res.push_back({nums[i],nums[j],nums[lhs],nums[rhs]});
                        //去重
                        while(lhs<rhs && nums[lhs] == nums[lhs+1]){
                            lhs++;
                        }
                        lhs++;
                        //去重
                        while(lhs<rhs && nums[rhs] == nums[rhs-1]){
                            rhs--;
                        }
                        rhs--;
                    }else if(sum > target){
                        rhs--;
                    }else{
                        lhs++;
                    }
                }
            }
        }
        return res;
    }
};