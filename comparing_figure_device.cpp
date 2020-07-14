#include<iostream>
#include<vector>
#include<random>
#include<cassert>
#include<algorithm>
#include<ctime>

using namespace std;

default_random_engine e;

void InsertSort(vector<int> &list) {
	if (list.size() < 2) {
		return;
	}
	for (int i = 1; i < list.size(); i++) {
		for (int j = i - 1; j >= 0 && list[j + 1] < list[j]; j--) {
			swap(list[j], list[j + 1]);
		}
	}
}

// for test
vector<int> generateRandomArray(int maxSize, int& size, int minValue, int maxValue) {
	assert(minValue < maxValue);
	size = e() % maxSize + 1;
	vector<int> list(size);
	for (int i = 0; i < list.size(); i++) {
		list[i] = e() % (maxValue - minValue) + minValue;
	}
	return list;
}

// for test
vector<int> copyArray(vector<int> list, const int n) {
	vector<int> list2(n);
	list2.assign(list.begin(), list.end());
	return list2;
}

// for test
void rightMethod(vector<int>& list, const int size) {
	sort(list.begin(), list.end());
}

// for test
bool isEqual(vector<int>& list1, vector<int>& list2, const int size) {
	for (int i = 0; i < size; i++) {
		if (list1[i] != list2[i])
			return false;
	}
	return true;
}

// for test
void printArray(vector<int>& list, const int size) {
	for (int i = 0; i < size; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

void testAlgorithm() {
	int testTime = 500000;
	int maxSize = 10;
	int minValue = -100;
	int maxValue = 100;
	bool succeed = true;
	clock_t startTime, endTime;
	int size = 0;
	startTime = clock();
	for (int i = 0; i < testTime; i++) {
		vector<int> list = generateRandomArray(maxSize, size, minValue, maxValue);
		vector<int> list1 = copyArray(list, size);
		vector<int> list2 = copyArray(list, size);
		InsertSort(list1);
		rightMethod(list2, size);
		if (!isEqual(list1, list2, size)) {
			succeed = false;
			printArray(list2, size);
			break;
		}
	}
	cout << (succeed ? "NICE" : "FUCKED") << endl;
	endTime = clock();
	cout << "time cost:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

int main()
{
	testAlgorithm();

	system("PAUSE");
	return 0;
}
