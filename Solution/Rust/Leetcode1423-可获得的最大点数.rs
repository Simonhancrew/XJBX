impl Solution {
    pub fn max_score(card_points: Vec<i32>, k: i32) -> i32 {
        let n:usize = card_points.len();
        let windowsize:usize = n - k as usize;
        let mut sum:i32 = 0;
        for i in 0..windowsize{
            sum += card_points[i];
        }
        let mut minsum = sum;
        for i in windowsize..n{
            sum += card_points[i] - card_points[i-windowsize];
            minsum = minsum.min(sum);
        }
        let mut total = 0;
        for i in card_points.iter(){
            total += i;
        }
        total - minsum
    }
}