#include <vector>
using namespace std;
//因为炸弹的传递性，可以dp成对所有位置放炸弹
//对于四个方向，没必要开四个dp数组，复用一个就可以
//ij位置是炸弹就dp[i][j] = 1,然后加上四个方向可以引爆的之前的子问题求出来值
//注意四个方向的初始化顺序要遵循方向序
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>> &grid){
        if(grid.empty()){
            return 0;
        }
        int row = grid.size(),column = grid[0].size();
        if(row == 0||column == 0){
            return 0;
        }
        vector<vector<int>> dp(row,vector<int> (column,0));
        vector<vector<int>> result(row,vector<int> (column,0));
        //up，初始dp为全0
        for(int i = 0;i < row;++i){
            for(int j = 0;j < column;++j){
                //如果这个地方是墙，直接0，不继续处理他的传递
                if(grid[i][j] == 'W'){
                    dp[i][j] = 0;
                }else{
                    //是enemy，基准1
                    if(grid[i][j] == 'E'){
                        dp[i][j] = 1;
                    }
                    //上方还有可以传递的子问题
                    if(i > 0){
                        dp[i][j] += dp[i-1][j];
                    }
                }
                result[i][j] += dp[i][j];
            }
        }
        //下面能炸死多少敌人,要反向对dp数组赋值
        for(int i = row-1;i >=0;--i){
            for(int j = 0;j<column;++j){
                if(grid[i][j] == 'W'){
                    dp[i][j] = 0;
                }else{
                    //因为复用了dp数组，所以要重新归零
                    dp[i][j] = 0;
                    if(grid[i][j] == 'E'){
                        dp[i][j] = 1;
                    }
                    if(i + 1 < row){
                        dp[i][j] += dp[i+1][j];
                    }
                }
                result[i][j] += dp[i][j];
            }
        }
        //左边能炸死多少
        for(int i = 0;i < row;++i){
            for(int j = 0;j < column;++j){
                if(grid[i][j] == 'W'){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = 0;
                    if(grid[i][j] == 'E'){
                        dp[i][j] = 1;
                    }
                    if(j > 0){
                        dp[i][j] += dp[i][j-1];
                    }
                }
                result[i][j] += dp[i][j];
            }
        }
        //右边能炸死多少
        for(int i = 0;i < row;++i){
            for(int j = column - 1;j >= 0;--j){
                if(grid[i][j] == 'W'){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = 0;
                    if(grid[i][j] == 'E'){
                        dp[i][j] = 1;
                    }
                    if(j + 1 < column){
                        dp[i][j] += dp[i][j+1];
                    }
                }
                result[i][j] += dp[i][j];
            }
        }
        //最后找到空地位置能炸死的最值
        int res = 0;
        for(int i = 0;i < row;++i){
            for(int j = 0;j < column;++j){
                if(grid[i][j] == '0'){
                    res = max(res,result[i][j]);
                }
            }
        }
        return res;
    }
};