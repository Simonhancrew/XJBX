impl Solution {
    pub fn xor_queries(arr: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans:Vec<i32> = Vec::new();
        let mut presum = Vec::new();
        presum.push(0);
        presum.push(arr[0]);
        let n = arr.len();
        for i in 1..n{
            let tmp = arr[i] ^ presum[i];
            presum.push(tmp);
        }
        for query in queries.iter(){
            let tmp = presum[query[1] as usize + 1] ^ presum[query[0] as usize];
            ans.push(tmp);
        }
        ans
    }
}