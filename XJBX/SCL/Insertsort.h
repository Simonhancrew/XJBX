#ifndef Insertsort
#define Insertsort
#include <vector>
using namespace std;
class insertsort
{
public:
	insertsort(vector<int> a):a(a) {}
	vector<int> a{};
	vector<int> sort();
};

vector<int> insertsort::sort() {
	for (int i = 1; i < a.size(); i++) {
		auto tmp = a[i];
		auto j = i;
		for (; j > 0 && a[j - 1] > tmp; j--) {
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
	return a;
}

#endif // !insertsort
#pragma once
