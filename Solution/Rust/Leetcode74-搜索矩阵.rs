impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let (n,m) = (matrix.len(),matrix[0].len());
        for i in 0..n{
            for j in 0..m{
                if matrix[i][j] == target{
                    return true;
                }else if matrix[i][j] > target{
                    return false; 
                }
            }
        }
        false
    }
}