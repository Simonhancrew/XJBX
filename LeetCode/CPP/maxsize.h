#pragma once
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
//abcabcbb
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, length = 0, result = 0;
        int sSize = s.size();
        unordered_map<char, int> hash;
        for (end = 0; end < sSize; end++) {
            char tmp = s[end];
            if (hash.find(tmp) != hash.end() && hash[tmp] >= start) {
                start = hash[tmp] + 1;
                length = end - start;
            }
            hash[tmp] = end;
            length++;
            result = max(result, length);
        }
        return result;
    }
};