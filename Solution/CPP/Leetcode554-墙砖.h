#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
//贪心 + 哈希，这条线必定穿过一个缝隙，统计每一个长度个数，最后用wall.size- max(缝隙数)就是答案
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> hash;
        for(auto &line:wall){
            int sum = 0;
            for(int i = 0;i < line.size() - 1;i ++){
                sum += line[i];
                hash[sum]++;
            }
        }
        int res = 0;
        for(auto kv:hash){
            res = max(res,kv.second);
        }
        return wall.size() - res;
    }
};