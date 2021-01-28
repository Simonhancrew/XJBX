#pragma once
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class manacher {
public:
	string manacherString(string& str) {
		int index = 0;
		string res(2*str.size()+1,' ');
		for (int i = 0; i != res.size(); i++) {
			res[i] = (i & 1) == 0 ? '#' : str[index++];//补#，让偶数时也可以向两边暴力扩
		}
		return res;
	}
	int maxLcpsLength(string str) {
		if (str.empty()) {
			return 0;
		}
		string charArr = manacherString(str);
		vector<int> pArr(charArr.length());
		int index = -1;
		int pr = -1;
		int max = INT_MIN;
		for (int i = 0; i != charArr.length(); i++) {
			pArr[i] = pr > i ? min(pArr[2 * index - i], pr - i) : 1;
			while (i + pArr[i]<charArr.length() && i - pArr[i]>-1) {
				if (charArr[i + pArr[i]] == charArr[i - pArr[i]]) {
					pArr[i]++;
				}
				else {
					break;
				}
			}
			if (i + pArr[i] > pr) {
				pr = i + pArr[i];
				index = i;
			}
			max = std::max(max, pArr[i]);
		}
		return max - 1;
	}
};