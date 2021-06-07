impl Solution {
    pub fn find_target_sum_ways(nums: Vec<i32>, target: i32) -> i32 {
        let  s:i32 = nums.iter().sum();
        if s  < target || (s + target) & 1 == 1{
            return 0;
        } 
        let pos = (s + target) >> 1;
        let mut dp = vec![0;pos as usize+1];
        dp[0] = 1;
        for i in 0..nums.len(){
            for j in (nums[i]..=pos).rev(){
                dp[j as usize] += dp[j as usize - nums[i] as usize];
            }
        }
        dp[pos as usize]
    }
}