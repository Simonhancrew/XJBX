impl Solution {
    pub fn max_frequency(nums:Vec<i32>, k: i32) -> i32 {
        let mut nums = nums;
        nums.sort_unstable();
        let(mut res,n,mut l) = (1,nums.len(),0);
        let mut need = 0;
        for r in 1..n{
            need += (r - l) as i32 * (nums[r] - nums[r - 1]);

            while need > k{
                need -= nums[r] - nums[l];
                l += 1;
            }
            res = res.max((r - l + 1) as i32);
        }
        res
    }
}