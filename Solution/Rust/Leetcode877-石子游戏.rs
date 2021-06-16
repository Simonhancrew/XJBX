impl Solution {
    pub fn stone_game(piles: Vec<i32>) -> bool {
        let mut res = piles[0];

        for i in 1..piles.len(){
            res ^= piles[i];
        }  
        if res == 0{
            return false;
        }
        true
    }
}