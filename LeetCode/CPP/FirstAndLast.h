#pragma once
#include <vector>
using namespace std;
class solution {
public:
	vector<int> searchrange(vector<int>& nums, int target) {
		vector<int> result;
		result.push_back(left_bound(nums, target));
		result.push_back(right_bound(nums, target));
		return result;
	}
private:
	int left_bound(vector<int>& nums, int target) {
		int begin = 0, end = nums.size() - 1;
		while (begin <= end) {
			int mid = (begin + end) / 2;
			if (target == nums[mid]) {
				if (mid == 0 || nums[mid-1]<target) {
					return mid;
				}
				end = mid - 1;
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
	int right_bound(vector<int>& nums, int target) {
		int begin = 0, end = nums.size() - 1;
		while (begin <= end) {
			int mid = (end + begin) / 2;
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