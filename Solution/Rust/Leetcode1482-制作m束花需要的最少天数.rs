impl Solution {
    pub fn min_days(bloom_day: Vec<i32>, m: i32, k: i32) -> i32 {
        if k * m > bloom_day.len() as i32{
            return -1;
        }
        let (mut l,mut r) = (bloom_day.iter().min().unwrap().clone(),bloom_day.iter().max().unwrap().clone());
        while l < r{
            let mid = l + r >> 1;
            if Self::check(mid,&bloom_day,k,m) {
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        if !Self::check(l,&bloom_day,k,m) {
            l = -1;
        }
        l
    }
    pub fn check(day:i32,bloom_day: &Vec<i32>,k:i32,m: i32) -> bool{
        let mut flowers = 0;
        let mut bqt = 0;
        for bloom in  bloom_day.iter(){
            if bloom <= &day{
                flowers += 1;
                if flowers == k{
                    bqt += 1;
                    if bqt == m{
                        break;
                    } 
                    flowers = 0;
                }
            }else{
                flowers = 0;
            }
        }
        bqt == m
    }
}