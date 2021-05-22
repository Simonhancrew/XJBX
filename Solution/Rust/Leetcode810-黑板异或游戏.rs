impl Solution {
    pub fn xor_game(nums: Vec<i32>) -> bool {
        if nums.len() % 2 == 0 {
            return  true;
        }
        let mut res = 0;
        for num in nums.iter(){
            res ^= num;
        }
        res == 0
    }
}