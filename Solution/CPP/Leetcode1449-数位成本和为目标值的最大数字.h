#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int dp[target + 1];
        memset(dp,-0x3f,sizeof dp);
        dp[0] = 0;
        for(int i = 0;i < 9;i++){
            for(int j = cost[i];j <= target;j++){
                dp[j] = max(dp[j],dp[j - cost[i]] + 1);
            }
        }
        if(dp[target] < 0) return "0";
        string ans;
        for(int i = 8,j = target;i >= 0;i--){
            while(j >= cost[i] && dp[j] == dp[j - cost[i]] + 1){
                ans += to_string(i + 1);
                j -= cost[i];
            }
        } 
        return ans;
    }
};