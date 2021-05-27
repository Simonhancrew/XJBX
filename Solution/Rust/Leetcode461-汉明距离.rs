impl Solution {
    pub fn hamming_distance(x: i32, y: i32) -> i32 {
        let (mut ans,mut s) = (0,x ^y);
        while s != 0{
            s -= (s & (-s));
            ans += 1;
        }
        return ans;
    }
}