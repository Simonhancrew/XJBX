impl Solution {
    pub fn total_hamming_distance(nums: Vec<i32>) -> i32 {
        let (mut res,n) = (0,nums.len() as i32);
        for i in 0..30{
            let mut c = 0;
            for num in nums.iter(){
                if num >> i & 1 == 0{
                    c += 1
                }
            }
            res += c * (n - c)
        }
        res
    }
}
