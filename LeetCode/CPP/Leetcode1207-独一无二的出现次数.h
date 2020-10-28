#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//利用一个哈希表映射数字和次数，此时的是key是无重复的
//然后开一个set去重value。
//如果二者的size是相同的则说明value都是不一样的，否则false
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> time;
        for(auto num:arr){
            time[num]++;
        }
        int n = arr.size();
        unordered_set<int> all;
        for(auto x:time){
            all.insert(x.second);
        }
        if(all.size() == time.size()){
            return true;
        }
        return false;;
    }
};