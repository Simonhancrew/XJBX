impl Solution {
    pub fn check_possibility(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut cnt = 0;
        //让数组可变
        let mut nums = nums;
        for i in 0..n-1{
            let x = nums[i];
            let y = nums[i+1];
            if x > y{
                cnt += 1 ;
                if cnt > 1{
                    return false;
                }
                if i > 0 && nums[i+1] < nums[i-1]{
                    nums[i+1] = nums[i];
                }
            }
        }
        true
    }
}