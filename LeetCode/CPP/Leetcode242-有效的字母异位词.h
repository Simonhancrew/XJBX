#include <string>
#include <algorithm>
using namespace std;
//排序O(nlogn)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};

#include <vector>
//维护一个26字母的哈希表
//一遍递增，一遍递减，有负数说明false
//O(n)复杂度
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> table(26, 0);
        for (auto& ch: s) {
            table[ch - 'a']++;
        }
        for (auto& ch: t) {
            table[ch - 'a']--;
            if (table[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};