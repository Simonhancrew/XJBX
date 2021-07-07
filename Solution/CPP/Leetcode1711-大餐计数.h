#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int,int> mp;
        int res = 0;
        int m = (*max_element(deliciousness.begin(),deliciousness.end())) * 2;
        for(auto& d:deliciousness){
            for(int i = 1;i <= m;i <<= 1){
                int pair = mp.count(i - d)?mp[i-d]:0;
                res = (pair + res) % MOD;
            }
            mp[d]++;
        }
        return res;
    }
};