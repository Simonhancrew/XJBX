impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        let (s1,s2) = (s1.into_bytes(),s2.into_bytes());
        let patternsize = s1.len();
        let n = s2.len();
        if patternsize > n{
            return false;
        }
        let mut nums1 = [0;26];
        let mut nums2 = [0;26];
        for i in 0..patternsize{
            nums1[s1[i] as usize - 'a' as usize] += 1;
            nums2[s2[i] as usize - 'a' as usize] += 1;
        }
        if nums1 == nums2{
            return true;
        }
        for i in patternsize..n{
            nums2[s2[i] as usize - 'a' as usize] += 1;
            nums2[s2[i - patternsize] as usize - 'a' as usize] -= 1;
            if nums1 == nums2{
                return true;
            }
        }
        false
    }
}