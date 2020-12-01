#pragma once
#include<vector>
using namespace std;
//≤¢≤ÈºØ≈Û”—»¶
class Disjointset {
public:
	Disjointset(int n) {
		for (int i = 0; i < n; i++) {
			_id.push_back(i);
			_size.push_back(1);
		}
		count = n;
	}
	int find(int p) {
		while (_id[p] != p) {
			_id[p] = _id[_id[p]];
			p = _id[p];
		}
		return p;
	}
	void union_(int p, int q) {
		int i = find(p);
		int j = find(q);
		if (i == j) {
			return;
		}
		if (_size[i] < _size[j]) {
			_id[i] = j;
			_size[j] += _size[i];
		}
		else {
			_id[j] = i;
			_size[i] += _size[j];
		}
		count--;
	}
	int countn() {
		return count;
	}
private:
	vector<int> _id;
	vector<int> _size;
	int count;
};

class solution547 {
	int findfriendcircle(vector<vector<int>>& M) {
		Disjointset dis(M.size());
		for (int i = 0; i < M.size(); i++) {
			for (int j = i + 1; j < M.size(); j++) {
				if (M[i][j]) {
					dis.union_(i, j);
				}
			}
		}
		return dis.countn();
	}
};