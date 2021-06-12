impl Solution {
    pub fn largest_number(cost: Vec<i32>, target: i32) -> String {
        let target  = target as usize;
        let mut dp = vec![i32::MIN;target+1];
        dp[0] = 0;
        for i in 0..9{
            for j in cost[i] as usize..=target as usize{
                dp[j] = dp[j].max(dp[j - cost[i] as usize] + 1);
            }
        }
        if dp[target] < 0 {
            return "0".to_string();
        }
        let mut ans = String::new();
        let mut j = target as i32;
        for i in (0..=8).rev(){
            while j >= cost[i] && dp[j as usize] == dp[j as usize - cost[i] as usize] + 1{
                ans.push((b'1' + i as u8) as char);
                j -= cost[i];
            }
        }
        ans
    }
}