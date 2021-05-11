impl Solution {
    pub fn decode(encoded: Vec<i32>) -> Vec<i32> {
        let n = encoded.len() + 1;
        let mut ans:Vec<i32> = vec![0;n];
        let x = (1..=n).fold(0,|mul,i| mul ^ i );
        let cur = encoded.iter().step_by(2).fold(0, |mul ,i| mul ^ i);
        let last = cur ^ x as i32;
        ans[n - 1] = last;
        let mut i = n - 2;
        while i as i32 >= 0{
            ans[i] = ans[i + 1] ^ encoded[i];
            i -= 1;
        }
        ans
    }
}