impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let (mut i,mut j,mut k) = (0,n - 1,n- 1);
        let mut ans = vec![0;n];
        while i <= j{
            if nums[i] * nums[i] < nums[j] * nums[j] {
                ans[k] = nums[j] * nums[j];
                j -= 1;
            }else{
                ans[k] = nums[i] * nums[i];
                i += 1;
            }
            k -= 1;
        }
        ans
    }
}