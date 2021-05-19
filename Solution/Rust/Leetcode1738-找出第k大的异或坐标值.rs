impl Solution {
    pub fn kth_largest_value(matrix: Vec<Vec<i32>>, k: i32) -> i32 {
        let mut matrix = matrix;
        let (n,m) = (matrix.len(),matrix[0].len());
        let mut res= Vec::new();
        for i in 0..n{
            for j in 0..m{
                if i >= 1{
                    matrix[i][j] ^= matrix[i - 1][j];
                }
                if j >= 1{
                    matrix[i][j] ^= matrix[i][j - 1];
                }
                if i >= 1 && j >= 1{
                    matrix[i][j] ^= matrix[i - 1][j - 1]
                }
                res.push(matrix[i][j]);
            }
        }
        res.sort_by(|a,b| b.cmp(a));
        res[k as usize- 1]
    }
}