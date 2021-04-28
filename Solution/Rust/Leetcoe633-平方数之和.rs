impl Solution {
    pub fn judge_square_sum(c: i32) -> bool {
        if c == 0{
            return true;
        } 
        let c = c as f64;

        let mut i:f64 = 0.0;
        while i * i  <= c{
            let j = (c - i * i).sqrt();
            if j.ceil() == j.floor(){
                return true;
            }
            i += 1.0;
        }
        return false;
    }
}