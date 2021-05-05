impl Solution {
    pub fn delete_and_earn(nums: Vec<i32>) -> i32 {
        let &max = nums.iter().max().unwrap();
        let mut sum = vec![0;max as usize+ 1];
        for num in nums{
            sum[num as usize] += num;
        }
        let (mut old,mut now) = (sum[0],sum[1]);
        for i in 3..=max + 1{
            let tmp = now.max(old + sum[i as usize - 1]);
            old = now;
            now = tmp;
        }
        now
    }   
}