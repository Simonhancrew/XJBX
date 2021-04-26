impl Solution {
    pub fn ship_within_days(weights:Vec<i32>, d: i32) -> i32 {
        let mut o = *weights.iter().max().unwrap();
        let mut total = weights.iter().sum();
        while o < total {
            let mut mid: i32 = (o+total)/2;
            let mut curr_ship = 0;
            let mut used_days = 1;
            for w in &weights {
                if curr_ship + w > mid { 
                    used_days += 1;
                    curr_ship = 0;
                }       
                curr_ship += w;         
            }
            if used_days <= d {
                total = mid;
            }else {
                o = mid+1;
            }                
        }      
        return o;
    }
}