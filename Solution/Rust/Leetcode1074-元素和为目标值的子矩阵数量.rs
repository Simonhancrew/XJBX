use std::collections::HashMap;
impl Solution {
    pub fn num_submatrix_sum_target(matrix: Vec<Vec<i32>>, target: i32) -> i32 {
        let (n,m,mut ans) = (matrix.len(),matrix[0].len(),0);
        for i in 0..n{
            let mut presum = vec![0;m];
            for j in i..n{
                for k in 0..m{
                    presum[k] += matrix[j][k];
                }
                let mut mp = HashMap::new();
                mp.insert(0, 1);
                let (mut res,mut cur) = (0,0);
                for idx in 0..m{
                    cur += presum[idx];
                    if mp.contains_key(&(cur - target)){
                        res += mp[&(cur -target)];
                    }
                    let h = mp.entry(cur).or_insert(0);
                    *h += 1;
                }
                ans += res;
            }
        }
        ans
    }
}