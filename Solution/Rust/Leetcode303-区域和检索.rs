struct NumArray{
    sum:Vec<i32>,
}

impl NumArray {

    fn new(nums: Vec<i32>) -> Self {
        let mut sum = 0;
        let mut preSum = vec![0;nums.len() + 1];
        for i in 0..nums.len(){
            sum += nums[i];
            preSum[i + 1] = sum;
        }
        NumArray{sum:preSum}
    }
    
    fn sum_range(&self, i: i32, j: i32) -> i32 {
        self.sum[j as usize + 1] - self.sum[i as  usize]
    }
}