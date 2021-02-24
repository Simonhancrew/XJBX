//01互换的方法 1 - a和 ^= 1
impl Solution {
    pub fn flip_and_invert_image(a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (m,n) = (a.len(),a[0].len());
        let mut a = a;
        for i in 0..m{
            let (mut start,mut end) = (0,n - 1);
            while start < end{
                if a[i][start] == a[i][end]{
                    a[i][start] ^= 1;
                    a[i][end] ^= 1;    
                }
                start += 1;
                end -= 1;
            }
            if start == end{
                a[i][start] ^= 1;
            }
        }       
        a
    }
}