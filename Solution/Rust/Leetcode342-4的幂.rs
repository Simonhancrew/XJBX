impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        n > 0 && (n & -n) == n && n % 3 == 1
    }
}