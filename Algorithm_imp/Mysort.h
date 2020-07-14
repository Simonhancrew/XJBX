#pragma once
#include <vector>
using namespace std;
//11种排序算法的全实现
class Mysort {
public:
	//冒泡排序
	void BubbleSort(vector<int>& nums) {
		if (nums.size() == 0) {
			return;
		}
		int n = nums.size();
		bool swapped;
		for (int end = n - 1; end > 0; --end) {
			swapped = false;
			for (int i = 0; i < end; i++) {
				if (nums[i] > nums[i + 1]) {
					swap(nums[i], nums[i + 1]);
					swapped = true;
				}
			}
			if (!swapped) {
				return;
			}
		}
	}
	//鸡尾酒排序
	void DoubleDirectionBubbleSort(vector<int>& nums) {
		if (nums.size() == 0) {
			return;
		}
		int  left = 0, right = nums.size() - 1;
		bool swapped;
		while (left < right) {
			swapped = false;
			for (int i = left; i < right; i++) {
				if (nums[i] > nums[i + 1]) {
					swap(nums[i], nums[i + 1]);
					swapped = true;
				}
			}
			for (int i = right; i > left; i--) {
				if (nums[i - 1] > nums[i]) {
					swap(nums[i - 1], nums[i]);
					swapped = true;
				}
			}
			if (!swapped) {
				return;
			}
		}
	}
	//选择排序O(n*n)，不稳定
	void ChoosSort(vector<int>& nums) {
		if (nums.size() == 0) {
			return;
		}
		int n = nums.size();
		for (int i = 0; i < nums.size(); i++) {
			int minidx = i;
			for (int j = i + 1; j < n; j++) {
				if (nums[minidx] > nums[j]) {
					minidx = j;
				}
			}
			swap(nums[i], nums[minidx]);

		}
	}
	//插入排序，不稳定 O(N*N);
	void InsertSort(vector<int>& nums) {
		if (nums.size() == 0) {
			return;
		}
		for (int i = 1; i < nums.size(); i++) {
			int cur = nums[i];
			int j = i - 1;
			while (j >= 0 && nums[j] > cur) {
				nums[j + 1] = nums[j];
				j--;
			}
			nums[j + 1] = cur;
		}
	}
	//希尔排序,gap选择长度折半序列,不稳定;
	void HillSort(vector<int>& nums) {
		if (nums.size() == 0) {
			return;
		}
		int n = nums.size();
		for (int gap = nums.size() >> 1; gap > 0; gap >>= 1) {
			for (int i = gap; i < n; i++) {
				int cur = nums[i];
				int j = i - gap;
				while (j >= 0 && nums[j] > cur) {
					nums[j + gap] = nums[j];
					j -= gap;
				}
				nums[j + gap] = cur;
			}
		}
	}
	//快速排序，不稳定；没有优化递归版本，选用霍尔分割
	void QuickSort(vector<int>& nums) {
		if (nums.size() == 0) {
			return;
		}
		hoareSort(nums, 0, nums.size() - 1);
	}
	//归并排序，稳定
	void mergeSort(vector<int>& nums) {
		mergeSort(nums, 0, nums.size() - 1);
	}
	void mergeSort(vector<int>& nums, int L, int R) {
		if (nums.size() == 0) {
			return;
		}
		if (L == R) {
			return;
		}
		int mid = L + ((R - L) >> 1);
		mergeSort(nums, L, mid);
		mergeSort(nums, mid + 1, R);
		merge(nums, L, mid, R);

	}
	//堆排序O（nLogn）不稳定
	void priorityqueSort(vector<int>& nums) {
		if (nums.size() == 0||nums.size()==1) {
			return;
		}
		buildMaxHeap(nums, nums.size() - 1);
		for (int end = nums.size() - 1; end > 0; end--) {
			swap(nums[0], nums[end]);
			siftDown(nums, 0, end - 1);
		}
	}
	//计数排序；稳定O（n+k）,数字<k
	void coutSort(vector<int>& nums, int k) {
		if (nums.size() == 0) {
			return;
		}
		vector<int> index(k + 1, 0);
		for (auto i : nums) {
			++index[i];
		}
		int start = 0;
		for (int i = 0; i <= k; i++) {
			int count = index[i];
			index[i] = start;
			start += count;
		}
		vector<int> tmp(nums.size(), 0);
		for (auto i : nums) {
			int idx = index[i];
			tmp[idx] = i;
			++index[i];
		}
		nums = tmp;
	}
	//桶排序
	//基数排序


private:
	//快排
	int hoarePartition(vector<int>& nums, int low, int high) {
		int pivot = nums[low + (high - low) / 2];
		int i = low, j = high;
		while (true) {
			while (nums[i] < pivot) {
				i++;
			}
			while (nums[j] > pivot) {
				j--;
			}
			if (i >= j) {
				return j;
			}
			swap(nums[i++], nums[j--]);
		}
	}
	void hoareSort(vector<int>& nums, int low, int high) {
		if (low < high) {
			int k = hoarePartition(nums, low, high);
			hoareSort(nums, low, k);
			hoareSort(nums, k + 1, high);
		}
	}
	//归并的merge
	void merge(vector<int>& nums, int L, int mid, int R) {
		vector<int> tmp(R - L + 1, 0);
		int i = 0;
		int p1 = L;
		int p2 = mid + 1;
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
	//堆排
	void siftDown(vector<int>& nums, int i, int end) {
		int parent = i, child = 2 * parent + 1;
		while (child <= end) {
			if (child + 1 <= end && nums[child + 1] > nums[child]) {
				child++;
			}
			if (nums[parent] >= nums[child]) {
				break;
			}
			swap(nums[child], nums[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
	}
	void buildMaxHeap(vector<int>& nums, int end) {
		for (int i = end / 2; i >= 0; i--) {
			siftDown(nums, i, end);
		}
	}
};