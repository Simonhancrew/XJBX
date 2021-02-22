impl Solution {
    pub fn is_toeplitz_matrix(matrix: Vec<Vec<i32>>) -> bool {
        let (m,n) = (matrix.len(),matrix[0].len());
        for i in 1..m{
            for j in 1..n{
                if matrix[i - 1][j - 1] != matrix[i][j]{
                    return false;
                }
            }
        }
        true    
    }
}