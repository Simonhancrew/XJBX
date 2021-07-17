impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let (mut n,mut ans) = (nums.len(),nums[0]);
        let mut dp = vec![0;2];
        dp[0] = nums[0];
        let (mut old,mut now) = (0,0);
        for i in 1..n{
            old = now;
            now = 1 - now;
            dp[now] = nums[i].max(dp[old] + nums[i]);
            ans = ans.max(dp[now])
        } 
        ans
    }
}