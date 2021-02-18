impl Solution {
    pub fn min_k_bit_flips(a: Vec<i32>, k: i32) -> i32 {
        let n = a.len();
        let [mut ans,mut cnt] = [0,0];
        let k = k as usize;
        let mut dif = vec![0;n+1];
        for i in 0..n{
            cnt += dif[i];
            if (a[i] + cnt) % 2 == 0{
                if i + k > n{
                    return -1;
                }
                ans += 1;
                cnt += 1;
                dif[i + k] -= 1;
            }
        }
        ans
    }
}