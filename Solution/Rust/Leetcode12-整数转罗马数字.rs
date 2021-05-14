impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let mut num = num;
        let map = [(1000, "M"), (900, "CM"), (500, "D"), (400, "CD"), (100, "C"), (90, "XC"), 
          (50, "L"), (40, "XL"), (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I")];
        let mut output = String::new();
        for (value, symbol) in map.iter(){
            while num >= *value{
                num -= value;
                output.push_str(symbol);
            }
            if num == 0{
                break;
            }
        }
        return output;
    }
}