impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
        let (mut l,mut r) = (1,n);
        while l < r {
            let mid = ((l as i64 + r as i64) >> 1) as i32;
            if self.isBadVersion(mid){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        l
    }
}