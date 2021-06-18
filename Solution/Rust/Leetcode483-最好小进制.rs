impl Solution {
    pub fn smallest_good_base(n: String) -> String {
        let n:i64 = n.parse().unwrap();
        for t in (3..=((n as f64).log2() + 1.0) as i64).rev(){
            let k = (n as f64).powf(1.0 / (t as f64 - 1.0)) as i64;
            let mut r = 0;
            for i in 0..t{
                r = r * k + 1;
            }
            if r == n {
                return k.to_string();
            }
        }
        (n - 1).to_string()
    }
}