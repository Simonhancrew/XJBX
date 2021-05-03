impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut res = 0;
        let mut x = x;
        while x != 0{
            //max 和 min in rust
            if res > i32::MAX / 10 || res < i32::MIN / 10{
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }
        res 
    }
}