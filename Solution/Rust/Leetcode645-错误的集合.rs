impl Solution {
    pub fn find_error_nums(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut dt = vec![0;n + 1];
        let mut ans = Vec::new();
        for &num in nums.iter(){
            dt[num as usize] += 1;
            if dt[num as usize] > 1{
                ans.push(num);
            }
        }
        for i in 1..=n{
            if dt[i] == 0{
                ans.push(i as i32);
                break;
            }
        }
        ans
    }
}