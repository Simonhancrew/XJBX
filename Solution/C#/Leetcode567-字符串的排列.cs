public class Solution {
    public bool CheckInclusion(string s1, string s2) {
        int patternsize = s1.Length;
        int n = s2.Length;
        if(patternsize > n){
            return false;
        }
        int[] nums1 = new int[26];
        int[] nums2 = new int[26];
        for(int i = 0;i < patternsize;i++){
            nums1[s1[i] - 'a']++;
            nums2[s2[i] - 'a']++;
        }
        if(compare(nums1,nums2)){
            return true;
        }
        for(int i = patternsize;i < n;i++){
            nums2[s2[i] - 'a']++;
            nums2[s2[i - patternsize] - 'a']--; 
            if(compare(nums1,nums2)){
                return true;
            }
        }       
        return false;
    }
    public bool compare(int[] nums1,int[] nums2){
        if(nums1 == null || nums2 == null || nums1.Length != nums2.Length){
            return false;
        }
        for(int i = 0;i < nums1.Length;i++){
            if(nums1[i] != nums2[i]){
                return false;
            }
        }
        return true;
    }
}