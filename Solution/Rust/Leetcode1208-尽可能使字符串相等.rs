impl Solution {
    pub fn equal_substring(s: String, t: String, max_cost: i32) -> i32 {
        let (mut start,mut end,mut cost) = (0,0,0);
        let mut res = 0;
        let (s,t) = (s.into_bytes(),t.into_bytes());
        //维护一个窗口，窗口的尾部是一直往前走的，窗口内的cost只要大于maxcost就往前移动头部
        //直到窗口内部cost是小于等于maxcost的
        while end <  s.len(){
            cost += (s[end] as i32 - t[end] as i32).abs();
            while cost > max_cost{
                cost -= (s[start] as i32 - t[start] as i32).abs();
                start += 1;
            }
            res = res.max(end - start + 1);
            end += 1;
        }
        res as i32
    }
}