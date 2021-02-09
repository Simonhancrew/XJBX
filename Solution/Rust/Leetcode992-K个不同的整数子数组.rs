impl Solution {
    pub fn subarrays_with_k_distinct(a: Vec<i32>, k: i32) -> i32 {
        let n = a.len();
        let mut start1 = 0;
        let mut start2 = 0;
        let mut end = 0;
        let mut total1 = 0;
        let mut total2 = 0;
        let mut ans = 0;
        let mut nums1=vec![0;n+1];
        let mut nums2=vec![0;n+1];
        while end < n{
            if nums1[a[end] as usize] == 0{
                total1 += 1;
            }
            nums1[a[end] as usize] += 1;
            if(nums2[a[end] as usize] == 0){
                total2 += 1;
            }
            nums2[a[end] as usize] += 1;
            while total1 > k{
                nums1[a[start1] as usize] -= 1;
                if nums1[a[start1] as usize] == 0{
                    total1 -= 1;
                }
                start1 += 1;
            }
            while total2 > k - 1{
                nums2[a[start2] as usize] -= 1;
                if nums2[a[start2] as usize] == 0{
                    total2 -= 1;
                }
                start2 += 1;
            }
            ans += start2 - start1;
            end += 1;
        }
        ans as i32
    }
}