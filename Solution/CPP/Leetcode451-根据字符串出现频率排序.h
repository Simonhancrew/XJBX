#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto &ch:s){
            mp[ch]++;
        }
        vector<pair<char,int>> vec;
        for(auto pii:mp){
            vec.push_back(pii);
        }
        sort(vec.begin(),vec.end(),[](auto &lhs,auto &rhs){
            return lhs.second > rhs.second;
        });
        string ans = "";
        for(auto &pii:vec){
            for(int i = 0;i < pii.second;i++){
                ans.push_back(pii.first);
            }
        }
        return ans;
    }
};