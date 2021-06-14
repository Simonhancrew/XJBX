impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let (mut l,mut r) = (1,n);
        while l < r{
            let mid = l + (r - l) / 2;
            if(guess(mid) > 0){
                l = mid + 1;
            }else{
                r = mid;
            }
        }  
        l
    }
}