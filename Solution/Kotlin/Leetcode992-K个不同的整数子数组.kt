class Solution {
    fun subarraysWithKDistinct(A: IntArray, K: Int): Int {
        val n = A.size
        var ans = 0
        var total1 = 0
        var total2 = 0
        var start1 = 0
        var start2 = 0
        var end = 0
        var nums1 = IntArray(n + 1)
        var nums2 = IntArray(n + 1)
        while (end  < n){
            if(nums1[A[end]] == 0){
                total1++
            }
            nums1[A[end]]++
            if(nums2[A[end]] == 0){
                total2++
            }
            nums2[A[end]]++
            while(total1 > K){
                nums1[A[start1]]--
                if(nums1[A[start1]] == 0){
                    total1--
                }
                start1++
            }
            while(total2 > K -1){
                nums2[A[start2]]--
                if(nums2[A[start2]] == 0){
                    total2--
                }
                start2++
            }
            ans += start2 - start1
            end++
        }
        return ans    
    }
}