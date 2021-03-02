#include <vector>
using namespace std;
//按照坐标不好处理的话就选择多开一位
//设置一个dummy的dp位置
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(); 
        if(m > 0){
            int n = matrix[0].size();
            dp.resize(m + 1, vector<int>(n + 1));
            dp[0][0] = matrix[0][0];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + matrix[i][j];
                }
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = dp[row2 + 1][col2 + 1];
        int left = 0, up = 0, mix = 0;
        left = dp[row2 + 1][col1];
        up = dp[row1][col2 + 1];
        mix = dp[row1][col1];
        return total - left - up + mix;
    }
    vector<vector<int>> dp;
};