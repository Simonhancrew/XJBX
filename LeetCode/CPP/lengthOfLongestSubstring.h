#pragma once
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class solution {
	int logest(string& s) {
		int start(0), end(0), length(0), result(0);
		int right = s.size();
		unordered_map<char, int> hash;
		while (end < right) {
			char tmp = s[end];
			if (hash.find(end) != hash.end() && hash[tmp] >= start) {
				start = hash[tmp] + 1;
				length = end - start;
			}
			hash[tmp] = end;
			end++;
			length++;
			result = max(length, result);
		}
	}
};