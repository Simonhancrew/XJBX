impl Solution {
    pub fn remove_duplicates(s: String) -> String {
        let mut stack = vec![];
        for byte in s.bytes() {
            match stack.last() {
                Some(&last) if last == byte => {
                    stack.pop();
                }
                _ => stack.push(byte),
            };
        }
        unsafe { String::from_utf8_unchecked(stack) }
    }
}
