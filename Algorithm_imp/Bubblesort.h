#ifndef Bubble
#define Bubble
#include <vector>
using namespace std;
class bubblesort {
public:	
	bubblesort(vector<int> a) :a(a) {}
	vector<int> sort();
	int size() { return a.size(); }
	vector<int> a{};
};

vector<int> bubblesort::sort() {
	auto a1 = a;
	int temp;
	for (int i = 0; i < a.size() - 1; i++) {
		bool bChanged = false;
		for (int j = 0; j < a.size() - 1; j++) {
			if (a1[j+1] < a1[j]) {
				temp = a1[j+1];
				a1[j + 1] = a1[j];
				a1[j] = temp;
				bChanged = true;
			}
		}
		if (false == bChanged) {
			break;
		}
	}
	return a1;
}
#endif // !Bubble
#pragma once
