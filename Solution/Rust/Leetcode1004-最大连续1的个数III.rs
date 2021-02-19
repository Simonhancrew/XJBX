impl Solution {
    pub fn longest_ones(a: Vec<i32>, k: i32) -> i32 {
        let (mut ans,mut start,mut n) = (0,0,a.len());
        let mut zeros = 0;
        //遍历时usize，数组内index时usize
        for end in 0..n{
            if a[end] == 0{
                zeros += 1;
            }
            while zeros > k{
                if a[start] == 0{
                    zeros -= 1;
                }
                start += 1;
            }
            ans = ans.max(end - start + 1);
        }       
        ans as i32
    }
}