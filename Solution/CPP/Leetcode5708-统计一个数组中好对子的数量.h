#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> hash;
        //就是转之后相减相等的组合放到一个hash集合
        for(auto t:nums){
            int x = t;
            string s = to_string(x);
            reverse(s.begin(),s.end());
            x = stoi(s);
            hash[t - x]++;
        }
        int res = 0;
        const int mod = 1e9 + 7;
        for(auto [k,v]:hash){
            res = (res + (long long) v *(v - 1) / 2) % mod;
        }
        return res;
    }
};