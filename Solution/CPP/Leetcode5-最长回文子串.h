#include <vector>
#include <string>
using namespace std;
//最后一步，成功找到了一个最长回文串
//之前一步，去掉头尾，他仍然是一个回文串
//此时，长度区间是状态
//dp[i][j] = max(dp[i+1][j],dp[i][j-1],dp[i+1][j-1] + 2|(s[i] == s[j]))
//区间型动态规划,坐标型的
//找回文串长度类的，找到始末位置，要设置成dp[i][j]->i-j位置能不能构成字符串
//要注意动态规划的状态顺序
//我们从较短向较长的过度的
//区间动态规划不能按照i从小到大去算，需要按照j-i的大小，从小到大去算
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        vector<vector<int>> dp(n,vector<int>(n,false));
        //l是距离，i是坐标
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};


//对于每一个位置，我们扩充，看看能不能扩成回文串
//回文串分为偶数长度和奇数长度的，在这里分别处理
//然后相对的维护最长的ans
class Solution{
public:
    string longestPalindrome(string s){
        int n = s.size();
        string ans = "";
        vector<vector<bool>> dp(n,vector<bool> (n,false));
        for(int t = 0;t < n;++t){
            //奇数长度的回文串
            int i = t,j = t;
            while(i >= 0 && j < n && s[i] == s[j]){
                dp[i][j] = true;
                if(ans.size() < j - i + 1){
                    ans = s.substr(i,j-i+1);
                }
                --i,++j;
            }
            //偶数长度的回文串
            i = t,j = t+1;
            while(i >= 0 && j < n && s[i] == s[j]){
                dp[i][j] = true;
                if(ans.size() < j - i + 1){
                    ans = s.substr(i,j-i+1);
                }
                --i,++j;
            }
        }
        return ans;
    }
};

//记忆化的搜素
class Solution {
public:
    string ans = "";
    vector<vector<int>> memo;
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) {
            return ans;
        }
        for (int i = 0; i < n; ++i) {
            memo.push_back(vector<int>(n, -1));
        }
        compute(s, 0, n - 1);
        return ans;
    }
private:
    void compute(string& s, int i, int j) {
        if (i > j || memo[i][j] != -1) {
            return;
        }
        if (i == j) {
            memo[i][j] = 1;
            if (ans.size() < j - i + 1) {
                ans = s.substr(i, j - i + 1);
            }
        }
        else if (i == j - 1) {
            compute(s, i, i);
            compute(s, j, j);
            memo[i][j] = (s[i] == s[j]);
            if (memo[i][j] && ans.size() < j - i + 1) {
                ans = s.substr(i, j - i + 1);
            } 
        }
        else {
            compute(s, i, j - 1);
            compute(s, i + 1, j);
            compute(s, i + 1, j - 1);
            memo[i][j] = (s[i] == s[j]) && memo[i + 1][j - 1];
            if (memo[i][j] && ans.size() < j - i + 1) {
                ans = s.substr(i, j - i + 1);
            }
        }
    }
};