impl Solution {
    pub fn num_ways(steps: i32, arr_len: i32) -> i32 {
        let maxjump = arr_len.min(steps);
        let (steps,maxjump) = (steps as usize,maxjump as usize);
        let mut dp = vec![vec![0;maxjump];steps + 1];
        dp[0][0] = 1;
        let modi:i32 = 1e9 as i32 + 7;
        for i in 1..=steps{
            for j in 0..maxjump{
                dp[i][j] = dp[i - 1][j];
                if j >= 1{
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % modi;
                }
                if j + 1 < maxjump{
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % modi;
                }
            }
        }
        dp[steps][0]
    }
}