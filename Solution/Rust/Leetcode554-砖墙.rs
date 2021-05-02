use std::collections::HashMap;
impl Solution {
    pub fn least_bricks(wall: Vec<Vec<i32>>) -> i32 {
        let mut hash = HashMap::new();
        for line in wall.iter(){
            let mut sum = 0;
            let end = line.len() - 1;
            for i in 0..end{
               sum += line[i]; 
               let count = hash.entry(sum).or_insert(0);
                *count += 1;
            }
        }

        let mut res = 0;
        for (k,v) in hash{
            res = res.max(v);
        }
        wall.len() as i32 - res
    }
}