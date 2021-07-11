impl Solution {
    pub fn h_index(mut citations: Vec<i32>) -> i32 {
        let (mut res,n) = (0,citations.len());
        citations.sort_unstable();
        for i in (1..=n).rev(){
            if citations[n -i] >= i as i32{
                res = i as i32;
                break;
            }
        }
        res
    }
}