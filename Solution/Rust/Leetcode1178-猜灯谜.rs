impl Solution {
    pub fn find_num_of_valid_words(words: Vec<String>,mut puzzles: Vec<String>) -> Vec<i32> {
        let mut m=std::collections::HashMap::new();
        words.into_iter().for_each(|x|{
            let t=x.bytes().map(|x|x-b'a').fold(0i32,|s,x|s|(1<<x));
            if t.count_ones()<=7{*m.entry(t).or_default()+=1}
        });
        puzzles.into_iter().map(|x|{
            let mut t={
                let mut xx=x.bytes().map(|x|x-b'a');
                let t=(xx.next().unwrap()as i32)<<26;
                xx.fold(t,|s,x|s|(1<<x))
            };
            let flag=1<<(t>>26);
            t&=&((1<<27)-1);
            let (mask,mut ans)=(t|-2147483648,0);
            while t>=0{
                if let Some(t)=m.get(&(t|flag)){ans+=t}
                t=(t-1)&mask
            }
            ans
        }).collect()
    }
}
