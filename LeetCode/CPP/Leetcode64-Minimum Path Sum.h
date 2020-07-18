#include <stdio.h>

#include <vector>

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

