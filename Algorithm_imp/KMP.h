#pragma once
#include <string>
#include <vector>
using namespace std;
class Kmp {
public:
	int getIndexOf(const string &s,const string &m) {
		if (s.empty() || m.empty() || s.size() < m.size()) {
			return -1;
		}
		int si = 0;
		int mi = 0;
		vector<int> next = getNextArray(m);
		while(si<s.length()&&mi<m.length()){
			if (s[si] == m[mi]) {
				si++;
				mi++;
			}
			else if (next[mi] == -1) {
				si++;
			}
			else {
				mi = next[mi];
			}
		}
		return mi == m.length() ? si - mi: -1;
	}
	vector<int> getNextArray(const string& m) { 
		vector<int> next;
		if (m.size() == 1) {
			next.push_back(-1);
		}
		next.resize(m.size());
		next[0] = -1;
		next[1] = 0;
		int pos = 2, cn = 0;
		while (pos < next.size()) {
			if (m[pos - 1] == m[cn]) {
				next[pos++] = ++cn;
			}
			else if (cn > 0) {
				cn = next[cn];
			}
			else
			{
				next[pos++] = 0;
			}
		}
		return next;
	}
};