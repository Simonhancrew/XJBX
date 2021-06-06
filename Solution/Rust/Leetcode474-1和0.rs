impl Solution {
    pub fn find_max_form(strs: Vec<String>, m: i32, n: i32) -> i32 {
        let (m,n) = (m as usize,n as usize);
        let mut dp = vec![vec![0;n + 1];m + 1];
        for s in strs.iter(){
            let (mut cn,mut cm) = (0,0);
            for ch in s.chars(){
                if ch == '0'{
                    cm += 1;
                }else{
                    cn += 1;
                }
            }
            for i in (cm..=m).rev(){
                for j in (cn..=n).rev(){
                    dp[i][j] = dp[i][j].max(dp[i - cm][j - cn] + 1);
                }
            }
        }
        dp[m][n]
    }
}