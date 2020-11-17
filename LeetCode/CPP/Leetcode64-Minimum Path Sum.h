#include <stdio.h>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(std::vector<std::vector<int> >& grid) {
    	if (grid.size() == 0){
	    	return 0;
	    }
	    int row = grid.size();
    	int column = grid[0].size();
    	std::vector<std::vector<int> > 
						dp(row, std::vector<int>(column, 0));
    	
	    dp[0][0] = grid[0][0];
	    for (int i = 1; i < column; i++){
    		dp[0][i] = dp[0][i-1] + grid[0][i];
    	}
	    for (int i = 1; i < row; i++){
	    	dp[i][0] = dp[i-1][0] + grid[i][0];
    		for (int j = 1; j < column; j++){
		    	dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
		    }
    	}
	    return dp[row-1][column-1];
    }
};

//滚动数组优化
class Solution {
public:
    int minPathSum(std::vector<std::vector<int> >& grid){
		//特殊情况处理
		if(grid.size() == 0 ||grid[0].size() == 0) {
			return 0;
		}
		int row = grid.size();
		int column = grid[0].size();
		//开dp数组
		vector<vector<int>> dp(2,vector<int> (column));
		//操作now = 0，old = 1
		//因为是滚动的，其实无所谓
		int now = 0,old = 1;
		//暂存上面和左边来的值
		int t1,t2;
		for(int i = 0;i < row;++i){
			//滚动数组的复用
			//old存之前的信息
			old = now;//old is row i-1
			//now更新信息
			now = 1 - now;//now is i
			for(int j = 0;j < column;++j){
				//边角处理
				if(i == 0 && j == 0){
					dp[now][j] = grid[i][j];
					continue;
				}
				//最小基准，grid当前值
				dp[now][j] = grid[i][j];
				//已经跑过一层了
				if(i > 0){
					t1 = dp[old][j];
				}else{
					t1 = INT_MAX;
				}
				//已经跑过在这一层跑过一列了
				if(j > 0){
					t2 = dp[now][j-1];
				}else{
					t2 = INT_MAX;
				}
				//加最小的
				if(t1 < t2){
					dp[now][j] += t1;
				}else{
					dp[now][j] += t2;
				}
			}
		}
		return dp[now][column - 1];
	}
};