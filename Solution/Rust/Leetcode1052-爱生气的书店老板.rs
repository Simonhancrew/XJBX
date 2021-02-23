impl Solution {
    pub fn max_satisfied(customers: Vec<i32>, grumpy: Vec<i32>, x: i32) -> i32 {
        let n = customers.len();
        let mut init = 0;
        for i in 0..n{
            init += if grumpy[i] == 0{
                customers[i]
            }else{
                0
            };
        }
        let x = x as usize;
        let mut increase = 0;
        for i in 0..x{
            increase += grumpy[i] * customers[i];
        }
        let mut maxincrease = increase;
        for i in x..n{
            increase += grumpy[i] * customers[i] - customers[i - x] * grumpy[i - x];
            maxincrease = maxincrease.max(increase);
        }
        init + maxincrease
    }
}