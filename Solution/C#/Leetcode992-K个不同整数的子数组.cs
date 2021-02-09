public class Solution {
    public int SubarraysWithKDistinct(int[] A, int K) {
        int n = A.Length;
        int ans = 0;
        int start1 = 0,start2 = 0;
        int total1 = 0,total2 = 0;
        int end = 0;
        int[] nums1 = new int[n + 1];
        int[] nums2 = new int[n + 1];
        while (end < n){
            if(nums1[A[end]] == 0){
                total1++;
            }
            nums1[A[end]]++;
            if(nums2[A[end]] == 0){
                total2++;
            }
            nums2[A[end]]++;
            while(total1 > K){
                nums1[A[start1]]--;
                if(nums1[A[start1]] == 0){
                    total1--;
                }
                start1++;
            } 
            while(total2 > K - 1){
                nums2[A[start2]]--;
                if(nums2[A[start2]] == 0){
                    total2--;
                }
                start2++;
            }
            ans += start2 - start1;
            end++;
        }
        return ans;
    }
}