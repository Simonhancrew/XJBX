impl Solution {
    pub fn convert_to_title(mut column_number: i32) -> String {
        let mut ans = Vec::new();
        while column_number > 0{
            column_number -= 1;
            ans.push(b'A' + (column_number % 26) as u8);
            column_number /= 26;
        }
        ans.reverse();
        String::from_utf8(ans).unwrap()
    }
}