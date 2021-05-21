impl Solution {
    pub fn max_uncrossed_lines(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let (n,m) = (nums1.len(),nums2.len());
        let mut dp = vec![vec![0;m +1];n + 1];  
        for i in 1..=n{
            for j in 1..=m{
                dp[i][j] = dp[i- 1][j].max(dp[i][j - 1]);
                if nums1[i - 1] == nums2[j - 1]{
                    dp[i][j] = dp[i][j].max(dp[i - 1][j - 1] + 1);
                }
            }
        }
        dp[n][m]
    }
}
