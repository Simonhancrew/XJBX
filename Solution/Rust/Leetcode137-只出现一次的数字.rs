use std::collections::HashMap;

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut hash = HashMap::new();
        for num in nums{
            let count = hash.entry(num).or_insert(0);
            *count += 1;
        }
        let mut ans = 0;
        for (key,value) in &hash{
            if *value == 1{
                ans = *key;
                break;
            }
        }
        ans
    }
}