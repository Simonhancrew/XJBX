impl Solution {
    pub fn read_binary_watch(turned_on: i32) -> Vec<String> {
        let mut ans = Vec::new();
        for i in 0..(1 << 10){
            let mut s = 0;
            for j in 0..10{
                if (i >> j) & 1 == 1{
                    s += 1;
                }
            }
            if s == turned_on{
                let h = i >> 6;
                let m = i & 63;
                if h < 12 && m < 60{
                    ans.push(format!("{}:{:02}",h,m));
                }            
            }
        }
        ans
    }
}