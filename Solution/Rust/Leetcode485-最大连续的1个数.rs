impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let mut maxcount = 0;
        let mut count = 0;
        for num in nums{
            if num == 1{
                count += 1;
            }else{ 
                maxcount = maxcount.max(count);
                count = 0;
            }
        }
        maxcount = maxcount.max(count);
        maxcount
    }
}