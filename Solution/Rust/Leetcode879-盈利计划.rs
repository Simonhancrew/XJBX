impl Solution {
    pub fn profitable_schemes(n: i32, min_profit: i32, group: Vec<i32>, profit: Vec<i32>) -> i32 {
        let (min_profit,n) = (min_profit as usize,n as usize);
        let MOD = 1e9 as i32 + 7;
        let mut dp = vec![vec![0;min_profit + 1];n + 1];
        for i in 0..=n{
            dp[i][0] = 1;
        }
        for i in 0..group.len(){
            let (g,p) = (group[i] as usize,profit[i] as usize);
            for j in (g..=n).rev(){
                for k in (0..=min_profit).rev(){
                    dp[j][k] = (dp[j - g][if k > p {k - p} else {0}] + dp[j][k]) % MOD;
                }
            }
        }
        dp[n][min_profit]
    }
}