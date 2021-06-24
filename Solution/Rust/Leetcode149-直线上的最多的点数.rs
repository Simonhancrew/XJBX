use std::collections::HashMap;
impl Solution {
    pub fn max_points(points: Vec<Vec<i32>>) -> i32 {
        let mut res = 0;
        for p in points.iter(){
            let (mut dup,mut ver) = (0,0);
            let mut cnt:HashMap<String,i32> = HashMap::new();
            for q in points.iter(){
                if p == q{
                    dup += 1;
                }else if p[0] == q[0]{
                    ver += 1;
                }else{
                    let k = ((p[1] - q[1]) as f64 / (p[0] - q[0]) as f64).to_string(); 
                    *cnt.entry(k).or_insert(0) += 1;
                }
            }
            let mut cur = ver;
            for (_,t) in cnt.iter(){
                cur = cur.max(*t);
            }
            res = res.max(cur + dup);
        }
        res
    }
}