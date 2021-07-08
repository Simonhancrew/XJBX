impl Solution {
    pub fn num_subarrays_with_sum(nums: Vec<i32>, goal: i32) -> i32 {
        let (mut res,mut l1,mut l2) = (0,0,0);
        let n = nums.len();
        let (mut s1,mut s2) = (0,0);
        for r in 0..n{
            s1 += nums[r];
            while l1 <= r && s1 > goal{
                s1 -= nums[l1];
                l1 += 1;
            }
            s2 += nums[r];
            while l2 <= r && s2 >= goal{
                s2 -= nums[l2];
                l2 += 1;
            }
            res += l2 - l1;
        }
        res as i32
    }
}