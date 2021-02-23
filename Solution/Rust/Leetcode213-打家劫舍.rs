use std::cmp::max;

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n == 0{
            return 0;
        }
        if n == 1{
            return nums[0];
        }
        robRange(&nums,0,n-2).max(robRange(&nums,1,n-1))
    }
}

fn robRange(nums:&[i32],start:usize,end:usize) -> i32{
    if start == end{
        return nums[start];
    }
    let mut dp = vec![0;nums.len()];

    dp[start] = nums[start];
    dp[start + 1] = max(nums[start],nums[start + 1]);
    for i in (start + 2)..=end{
        dp[i] = max(dp[i - 1],dp[i - 2] + nums[i]);
    } 
    dp[end]
}