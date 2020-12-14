#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
//对每个字符排序，异位词的排序是唯一的
//作为map的key
//然后value写一个vector
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto str:strs){
            string key = str;
            sort(key.begin(),key.end());
            mp[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto it = mp.begin();it != mp.end();++it){
            res.push_back(it->second);
        }
        return res;
    }
};