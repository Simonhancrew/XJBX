#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> res;
        set<int> tables;
        set<string> foods;
        map<int,unordered_map<string,int>> d;
        for(auto& order:orders){
            tables.insert(stoi(order[1]));
            foods.insert(order[2]);
            d[stoi(order[1])][order[2]]++;
        }
        res.resize(1 + tables.size());
        res[0].push_back("Table");
        for(auto& food:foods){
            res[0].push_back(food);
        }
        int n = res[0].size();
        int idx = 1;
        for(auto tb:tables){
            res[idx].push_back(to_string(tb));
            for(int i = 1;i < n;i++){
                res[idx].push_back(d[tb].count(res[0][i])?to_string(d[tb][res[0][i]]):"0");
            }
            idx++;
        }
        return res;
    }
};