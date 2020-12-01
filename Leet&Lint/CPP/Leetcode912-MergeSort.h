#include <vector>
using namespace std;
class solution {
public:
	void mergeSort(vector<int>& nums,int L,int R) {
		if (nums.size() == 0) {
			return;
		}
		if (L == R) {
			return;
		}
		int mid = L + ((R - L) >> 1);
		mergeSort(nums,L, mid);
		mergeSort(nums,mid + 1, R);
		merge(nums, L, mid, R);

	}
private:
	void merge(vector<int> &nums, int L, int mid, int R) {
		vector<int> tmp(R-L+1,0);
		int i = 0;
		int p1 = L;
		int p2 = mid+1;
		while (p1 <= mid && p2 <= R) {
			tmp[i++] = nums[p1] > nums[p2] ? nums[p2++] : nums[p1++];
		}
		while (p1 <= mid) {
			tmp[i++] = nums[p1++];
		}
		while (p2 <= R) {
			tmp[i++] = nums[p2++];
		}
		for (auto i = 0; i < tmp.size(); i++) {
			nums[L + i] = tmp[i];
		}
	}
};
#pragma once
