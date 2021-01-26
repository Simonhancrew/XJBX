#include <vector>
#include <unordered_map>
using namespace std;
//先将骨牌按照一个顺序记录在哈希表种
//没多出一个相同值就又可以配对之前存在的数量骨牌数量的对数
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        vector<int> num(100);
        for(auto it:dominoes){
            int val = it[0] > it[1]?it[1] * 10 + it[0]:it[0] * 10 + it[1];
            ans += num[val];
            num[val]++;
        }
        return ans;
    }
};

class Solution{
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto it:dominoes){
            int val = it[0] < it[1]?it[0] * 10 + it[1]:it[1] * 10 + it[0];
            ans += mp[val];
            mp[val]++;
        } 
        return ans;
    }
};