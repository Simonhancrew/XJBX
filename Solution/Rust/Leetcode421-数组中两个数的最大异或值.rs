use std::collections:: HashSet;
impl Solution {
    pub fn find_maximum_xor(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut i = 30;
        for i in (0..=30).rev(){
            let mut st = HashSet::new();
            nums.iter().for_each(|num|{
                st.insert(num >> i);
            });
            let nex = 2 * ans + 1;
            let mut fd = false;
            for &num in nums.iter(){
                if st.contains(&(nex ^ (num >> i))){
                    fd = true;
                    break;
                }
            }
            if fd {
                ans = nex;
            }else{
                ans = nex - 1;
            }
        }
        ans
    }
}