impl Solution {
    pub fn is_monotonic(a: Vec<i32>) -> bool {
        let n = a.len();
        let (mut inc,mut dec) = (true,true);
        for i in 0..n-1{
            if a[i] > a[i + 1]{
                inc = false;
            }
            if a[i] < a[i + 1]{
                dec = false;
            }
        }
        dec || inc
    }
}