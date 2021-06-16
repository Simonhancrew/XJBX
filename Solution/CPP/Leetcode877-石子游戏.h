#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int dp[n][n];
        for(int len = 1;len <= n;len++){
            for(int i =0;i + len - 1 < n;i++){
                int j = i + len - 1;
                if(len == 1) dp[i][j] = piles[i];
                else{
                    dp[i][j] = max(piles[i] - dp[i + 1][j],piles[j] - dp[i][j - 1]);
                } 
            }
        }
        return dp[0][n - 1] > 0;
    }
};

