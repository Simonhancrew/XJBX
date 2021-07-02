#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i = 0;
        int ans = 0;
        while(i < costs.size() && coins >= costs[i]){
            coins -= costs[i++];
            ans++;
        }
        return ans;
    }
};