impl Solution {
    pub fn strange_printer(s: String) -> i32 {
        let n = s.len();
        let s = s.as_bytes();
        let mut dp = vec![vec![0;n + 1];n + 1];
        for leng in 1..=n{
            for i in 0..n + 1 - leng{
                let j = i + leng - 1;
                dp[i][j] = 1 + dp[i+1][j];
                for k in i+1..=j{
                    if s[i] == s[k]{
                        dp[i][j] = dp[i][j].min(dp[i][k - 1]+dp[k + 1][j]);
                    }   
                }
            }
        }
        dp[0][n - 1]
    }
}