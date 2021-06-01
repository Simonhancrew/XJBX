impl Solution {
    pub fn can_eat(candies_count: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<bool> {
        let n = candies_count.len();
        let mut presum = vec![0 as i64;n];
        presum[0] = candies_count[0] as i64;
        for i in 1..n{
            presum[i] = presum[i - 1] + candies_count[i] as i64;
        }

        let mut ans = Vec::new();
        for query in queries.iter(){
            let (ftype,day,cap) = (query[0] as i64,query[1] as i64,query[2] as i64);
            let (x1,y1) = (day + 1,(day+ 1) * cap);
            let (mut x2,y2) = (1 as i64,presum[ftype as usize]);
            if ftype > 0{
                x2 = presum[ftype as usize- 1] + 1;
            }
            ans.push(!(x1 > y2 || y1 < x2));
        }          
        ans   
    }
}