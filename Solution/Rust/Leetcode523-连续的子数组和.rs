use std::collections::HashMap;
impl Solution {
    pub fn check_subarray_sum(nums: Vec<i32>, k: i32) -> bool {
        let n = nums.len();
        if n < 2 {
            return false;
        }
        let mut re = 0;
        let mut mp = HashMap::new();
        mp.insert(0, -1 as i32);
        for i in 0..n{
            re = (re + nums[i]) % k;
            if mp.contains_key(&re){
                let idx = mp[&re];
                if i as i32- idx >= 2{
                    return true;
                }
            }else{
                mp.entry(re).or_insert(i as i32);
            }
        }
        return false;
    }
}