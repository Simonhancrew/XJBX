class Solution {
    public int maximalSquare(char[][] matrix) {
        int maxSide = 0;
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return maxSide;
        }
        int rows = matrix.length, columns = matrix[0].length;
        int[][] dp = new int[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = Math.max(maxSide, dp[i][j]);
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
}
/* dp(i,j) 表示以 (i, j)(i,j) 为右下角，且只包含 11 的正方形的边长最大值
如果该位置的值是 00，则 dp(i, j) = 0dp(i,j)=0
如果该位置的值是 11，则 dp(i, j)dp(i,j) 的值由其上方、左方和左上方的三个相邻位置的 dp值决定  
当前位置的元素值等于三个相邻位置的元素中的最小值加 11 
*/