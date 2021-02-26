#pragma once
#include <vector>
using namespace std;
class BinarySearch {
//数组要求有序
public:
	bool binarySearch(vector<int>& nums, int target) {
		int begin = 0;
		int end = nums.size() - 1;
		while (begin < end) {
			int mid = begin + (end - begin) / 2;
			if (nums[mid] == target) {
				return true;
			}
			else if (nums[mid] > target) {
				end = mid-1;
			}
			else if (nums[mid] < target) {
				begin = mid + 1;
			}
		}
		return false;
	}
	bool binarySearch(vector<int>& nums, int target,int begin,int end) {
		int mid = begin + (end - begin) / 2;
		if (begin > end) {
			return false;
		}
		if (target == nums[mid]) {
			return true;
		}
		else if (target > nums[mid]) {
			binarySearch(nums, target, mid+1, end);
		}
		else if (target < nums[mid]) {
			binarySearch(nums, target, begin, mid-1);
		}
	}
};