#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        hvalue[key].push_back(value);
        htime[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(!htime.count(key) || htime[key].size() == 0) return "";
        if(timestamp < *htime[key].begin()) return "";
        if(timestamp >= *htime[key].rbegin()) return hvalue[key].back();
        auto it = upper_bound(htime[key].begin(),htime[key].end(),timestamp);
        return hvalue[key][it - 1 - htime[key].begin()];
    }
    unordered_map<string,vector<string>> hvalue;
    unordered_map<string,vector<int>> htime;
};