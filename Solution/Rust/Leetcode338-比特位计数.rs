impl Solution {
    pub fn count_bits(num: i32) -> Vec<i32> {
        let num = num as usize;
        //前i位有多少1
        let mut dp = vec![0;num +1];
        for i in 1..=num{
            //当前的数右移一位，此数在状态转移中记录了1的个数，
            //再看这个数最后一位是否是1
            dp[i] = dp[i >> 1] + ((i as i32)%2);
        }
        dp
    }
}