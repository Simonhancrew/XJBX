impl Solution {
    pub fn max_length(arr: Vec<String>) -> i32 {
        let (mut ans,n) = (0,arr.len());
        for i in 0..(1 << n){
            let mut st = vec![0;26];
            let mut flag = false;
            for j in 0..n{
                if (i >> j) & 1 == 1 {
                    for ch in arr[j].chars(){
                        st[(ch as u32- 'a' as u32) as usize] += 1;
                        if st[(ch as u32- 'a' as u32) as usize] > 1{
                            flag = true;
                            break;
                        }
                    }
                }
                if flag{
                    break;
                }
            }
            if !flag{
                ans = ans.max(st.iter().sum());
            }
        }
        ans
    }
}