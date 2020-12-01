#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>{leftBound(nums,target),rightBound(nums,target)};
    }
private:
    int leftBound(vector<int> &nums,int target){
        int begin = 0,end = nums.size() - 1;
		//二分查找的细节，如果时闭区间的话，要用<=
        while(begin <= end){
            int mid = begin + ((end - begin) >> 1);
            if(nums[mid] == target){
                if(mid == 0 ||nums[mid - 1] < target){
                    return mid;
                }
                end = mid - 1;
            }else if(nums[mid] < target){
                begin = mid + 1;
            }else if(nums[mid] > target){
                end = mid - 1;
            }
        }
        return -1;
    }
	int rightBound(vector<int>& nums, int target) {
		int begin = 0, end = nums.size() - 1;
		while (begin <= end) {
			int mid = begin + ((end - begin) >> 1);
			if (nums[mid] == target) {
				if (mid == nums.size() - 1|| nums[mid+1]>target) {
					return mid;
				}
				begin = mid + 1;
			}
			else if (nums[mid] > target) {
				end = mid - 1;
			}
			else if (nums[mid] < target) {
				begin = mid + 1;
			}
		}
		return -1;
	}    
};