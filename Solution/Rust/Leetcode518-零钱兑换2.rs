impl Solution {
    pub fn change(amount: i32, coins: Vec<i32>) -> i32 {
        let amount = amount as usize;
        let n = coins.len();
        let mut dp = vec![0;amount + 1];
        dp[0] = 1;
        for i in 0..n{
            for j in (coins[i] as usize)..=amount{
                dp[j] += dp[j- coins[i] as usize];
            }
        } 
        dp[amount]
    }
}