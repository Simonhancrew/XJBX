#include <vector>

using namespace std;

class Solution {
public:
    using ll = long long;
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = queries.size();
        int candynum = candiesCount.size();
        vector<ll> presum(candynum);
        presum[0] = candiesCount[0];
        for(int i = 1;i < candynum;i++){
            presum[i] = presum[i - 1] + candiesCount[i];
        }
        
        vector<bool> ans;
        for(int i = 0;i < n;i++){
            auto query = queries[i];
            int type = query[0],day = query[1],cap = query[2];
            ll x1 = day + 1,y1 = (ll)(day + 1) * cap;
            ll x2 = (type == 0 ?1:presum[type - 1] + 1),y2 = presum[type];
            ans.push_back(!(x1 > y2 || y1 < x2));
        }
        return ans;
    }
};