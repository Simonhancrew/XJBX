#include <vector>
#include <algorithm>
using namespace std;
//坐标动态规划
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        int res = 0;
        int m = matrix.size(),n = matrix[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int>(3,0)));
        //当前的dp最后一维，记录边长和面积
        for (int i = 0;i < m;i++){
            for(int j = 0;j < n;++j){
                if(matrix[i][j] == '1'){
                    if(i == 0 && j == 0){
                        //前两个值是边长，最后一个是面积
                        dp[i][j] = {1,1,1};
                    }
                    //第一行
                    else if(i == 0){
                        dp[i][j] = {dp[i][j - 1][0] + 1,1,dp[i][j - 1][2] + 1};
                    }
                    //第一列
                    else if(j == 0){
                        dp[i][j] = {1,dp[i - 1][j][1] + 1,dp[i - 1][j][2] + 1};
                    }
                    else{
                        dp[i][j][0] = dp[i][j - 1][0] + 1;//左边有多少个1,长
                        dp[i][j][1] = dp[i - 1][j][1] + 1;//上面有多少个1，宽
                        //计算面积
                        int colMin = dp[i][j][0],row = dp[i][j][1];
                        //找到向上走所有的行里可以的最大长
                        for(int k = 0;k < row;k++){
                            colMin = min(dp[i - k][j][0],colMin);
                            dp[i][j][2] = max(dp[i][j][2],colMin * (k + 1));
                        }
                    }  
                }    
                res = max(res,dp[i][j][2]);            
            }
        }
        return res;
    }
};