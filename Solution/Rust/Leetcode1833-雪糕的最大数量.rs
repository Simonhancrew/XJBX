impl Solution {
    pub fn max_ice_cream(mut costs: Vec<i32>, coins: i32) -> i32 {
        costs.sort();
        let (mut ans,mut i) = (0,0);
        let mut coins = coins;
        while i < costs.len() && coins >= costs[i] {
            coins -= costs[i];
            i +=  1;
            ans += 1;
        } 
        ans
    }
}