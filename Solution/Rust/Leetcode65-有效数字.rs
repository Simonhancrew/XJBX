impl Solution {
    pub fn is_number(s: String) -> bool {
        let eps = s.find('e');
        let Eps = s.find('E');
        fn ispurenumber(s:&str,mustbeint:bool) -> bool {
            let (mut hasdigit,mut hasdot) = (false,false);
            let st = if s.chars().nth(0) == Some('+') || s.chars().nth(0) == Some('-'){1} else {0};
            for i in st..s.len(){
                if s.chars().nth(i).unwrap() == '.'{
                    if mustbeint{
                        return false;
                    }
                    if hasdot{
                        return false;
                    }
                    hasdot = true;
                }else if s.chars().nth(i).unwrap().is_digit(10){
                    hasdigit = true;
                }else{
                    return false;
                }
            }
            hasdigit
        }
        if let Some(i) = eps{
            return ispurenumber(&s[0..i],false) && ispurenumber(&s[i+1..],true);
        }
        if let Some(i) = Eps{
            return ispurenumber(&s[0..i],false) && ispurenumber(&s[i+1..],true);
        }
        ispurenumber(&s,false)
    } 
}