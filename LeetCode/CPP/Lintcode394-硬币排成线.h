#include <vector>
using namespace std;
//博弈型动态规划
//必胜，走出合法的一步，然后队友必败
//必败，无论怎么走出合法的一步，自己都必败
//dp,面对n个石子，是否先手必胜。只要有一手能胜，就是必胜
class Solution {
public:
    bool firstWillWin(int n) {
        if(n == 0){
            return false;
        }
        if(n <= 2){
            return true;
        }
        vector<bool> dp(n + 1,0);
        dp[0] = false;
        dp[1] = true,dp[2] = true;
        for(int i = 3;i <= n;++i){
            //是否必胜
            dp[i] = (dp[i-1] == false)||(dp[i-2] == false);
        }
        return dp[n];
    }
};
//滚动数组优化
class Solution {
public:
    bool firstWillWin(int n) {
        if(n == 0){
            return false;
        }
        if(n <= 2){
            return true;
        }
        bool dp0 = false;
        bool dp1 = true,dp2 = true;
        bool dp3;
        for(int i = 3;i <= n;++i){
            //是否必胜
            dp3 = (dp2 == false)||(dp1 == false);
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp3;
    }
};

//数学解
class Solution {
public:
    bool firstWillWin(int n) {
        return n % 3 != 0;
    }
};
