impl Solution {
    pub fn count_triplets(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut presum = vec![0;n + 1];
        for i in 0..n{
            presum[i + 1] = presum[i] ^ arr[i]
        }
        let mut res = 0;
        for i in 0..n{
            for k in (i + 1)..n{
                if presum[i] == presum[k + 1]{
                    res += k - i;
                }
            }
        }
        res as i32
    }
}