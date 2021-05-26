impl Solution {
    pub fn reverse_parentheses(s: String) -> String {
        let n = s.len();
        let s  = s.as_bytes();
        let mut res = String::new();
        let mut stk = Vec::new();
        for i in 0..n{
            if s[i] == b'('{
                stk.push(res.clone());
                res = "".to_string();
            }else if s[i] == b')'{
                res = res.chars().rev().collect();
                res = stk.pop().unwrap().clone() + &res;
            }else{
                res.push(s[i] as char);
            }
        }
        res
    }
}