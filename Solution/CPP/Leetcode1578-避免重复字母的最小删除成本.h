#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//trick:利用while去处理重复
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.size();
        int i = 0;
        int ret = 0;
        while(i < n){
            auto ch = s[i];
            int maxv = 0;
            int sum = 0;
            while(i  < n && s[i] == ch){
                maxv = max(maxv,cost[i]);
                sum += cost[i];
                i++;
            }
            ret += (sum - maxv);
        }
        return ret;
    }
};

#include <numeric>
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int total = accumulate(cost.begin(),cost.end(),0);
        int i = 0,n = cost.size();
        int sum = 0;
        while(i < n){
            auto ch = s[i];
            int maxv = cost[i];

            while(i < n && ch == s[i]){
                maxv = max(maxv,cost[i]);
                i++;
            }
            sum += maxv;
        }
        return total - sum;
    }
};
