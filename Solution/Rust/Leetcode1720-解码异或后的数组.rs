impl Solution {
    pub fn decode(encoded: Vec<i32>, first: i32) -> Vec<i32> {
        let n = encoded.len()  + 1;
        let mut res = vec![0;n];
        res[0] = first;
        for i in 1..n{
            res[i] = res[i - 1] ^ encoded[i - 1];
        }
        res
    }
}