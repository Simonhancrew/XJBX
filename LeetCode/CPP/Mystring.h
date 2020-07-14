#pragma once
#include <string>
#include <vector>
#include <set>
using namespace std;
class  solution {
	set<char> exist;
	string K(string& a) {
		string B="";
		for (int i = 0; i < a.size(); i++) {
			if (exist.find(a[i]) == exist.end()) {
				B.append(1, a[i]);
				exist.insert(a[i]);
			}				
		}
		return B;
	}
};