use std::collections::HashMap;
impl Solution {
    pub fn find_max_length(nums: Vec<i32>) -> i32 {
        let (mut ans,n,mut cur) = (0,nums.len(),0);
        let mut mp = HashMap::new();
        let mut cnt = 0;
        mp.insert(0, -1);
        for (idx,num) in nums.into_iter().enumerate(){
            match num {
                1 =>{
                    cur = 1;
                },
                _ =>{
                    cur = -1;
                }
            }
            cnt += cur;
            if mp.contains_key(&cnt){
                ans = ans.max(idx as i32 - mp[&cnt]);
            }else{
                mp.entry(cnt).or_insert(idx as i32);
            }
        }
        ans
    }
}