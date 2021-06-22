impl Solution {
    pub fn permutation(mut s: String) -> Vec<String> {
        let s2byte = unsafe {s.as_bytes_mut()};
        s2byte.sort_unstable();
        let (mut ans,mut cur,mut st) = (vec![],vec![],vec![false;s2byte.len()]);
        Solution::dfs(s2byte,&mut cur,&mut ans,&mut st,0);
        ans
    }
    pub fn dfs(s2byte:&mut [u8],cur:&mut Vec<u8>,ans:&mut Vec<String>,st:&mut Vec<bool>,idx:usize){
        if idx == s2byte.len(){
            ans.push(unsafe {String::from_utf8_unchecked(cur.to_vec())});
            return;
        }
        for i in 0..s2byte.len(){
            if !st[i]{
                if i > 0 && st[i - 1] == false && s2byte[i - 1] == s2byte[i]{
                    continue;
                }
                st[i] = true;
                cur.push(s2byte[i]);
                Solution::dfs(s2byte,cur,ans,st,idx + 1);
                st[i] = false;
                cur.pop();
            }
        }
    }
}