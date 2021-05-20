#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string,int> hash;
        vector<pair<string,int>> fx;
        for(auto word:words){
            hash[word]++;
        }
        for(auto it:hash){  
            fx.push_back(it);
        }
        sort(fx.begin(),fx.end(),[](auto lhs,auto rhs){
            if(lhs.second == rhs.second) return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        });
        for(int i = 0;i < k;i++){
            res.push_back(fx[i].first);
        }
        return res;
    }
};