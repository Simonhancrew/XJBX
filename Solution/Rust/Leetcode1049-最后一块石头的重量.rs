// 合并的过程就是给每个重量前赋值正号或者负号的过程，相当于把这些石头分为两组，使得两组的差值尽可能小.
// 所以这是经典的集合划分 NP 完全问题，可以采用动态规划的方法求解。
// 即尽可能的让数组中添加符号的数字尽可能的接近 sum / 2
impl Solution {
    pub fn last_stone_weight_ii(stones: Vec<i32>) -> i32 {
        let n = stones.len();
        let s = stones.iter().sum();
        let wei = (s / 2) as usize;  
        let mut dp = vec![false;wei as usize + 1];
        dp[0] = true;//最开始的时候可以分割出0的组
        for i in 0..n{
            for j in (stones[i] as usize..=wei).rev(){
                dp[j] = dp[j] || dp[j - stones[i] as usize];
            }
        }
        for i in (0..=wei).rev(){
            if dp[i]{
                return s - 2 * i as i32;
            }
        }
        s
    }
}