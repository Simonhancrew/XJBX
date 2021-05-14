#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> hash = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    int romanToInt(string s) {
        int n = s.size();
        int res = hash[s[n - 1]];
        for(int i = n - 2;i >= 0;i--){
            int cur = hash[s[i]];
            int right = hash[s[i + 1]];
            if(cur >= right) res += cur;
            else res -= cur;
        }
        return res;
    }
};