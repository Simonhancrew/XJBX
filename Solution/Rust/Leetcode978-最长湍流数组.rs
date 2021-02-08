impl Solution {
    pub fn max_turbulence_size(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut start = 0;
        let mut end = 1;
        let mut direction = false;
        let mut ans = 1;
        while end < n{
            if start + 1 == end {
                if arr[end - 1 ] > arr[end]{
                    direction = true;
                    ans = ans.max(2);
                }else if arr[end - 1] < arr[end]{
                    direction = false;
                    ans = ans.max(2);
                }else{
                    start+=1;
                }
                end += 1 ;
            }else{
                if (arr[end-1] > arr[end] && !direction) || (arr[end-1] < arr[end] && direction){
                    ans = ans.max(end - start + 1);
                    end += 1;
                    direction = !direction;
                }else{
                    start = end - 1;
                }
            }
        }
        return ans as i32;
    }
}