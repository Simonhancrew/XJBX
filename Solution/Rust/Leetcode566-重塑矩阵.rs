impl Solution {
    pub fn matrix_reshape(nums: Vec<Vec<i32>>, r: i32, c: i32) -> Vec<Vec<i32>> {
        let row = nums.len();
        let col = nums[0].len();
        let (r,c) = (r as usize,c as usize);
        if col * row != c * r{
            return nums
        }
        let mut ans = vec![vec![0;c];r];
        for i in 0..r{
            for j in 0..c{
                let idx = (i * c + j);
                let (x,y) = (idx / col,idx % col);
                ans[i][j] = nums[x][y];
            }
        }
        ans
    }
}