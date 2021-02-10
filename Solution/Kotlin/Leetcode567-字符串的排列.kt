class Solution {
    fun checkInclusion(s1: String, s2: String): Boolean {
        val patternsize =  s1.length
        val n = s2.length
        if(n < patternsize){
            return false
        }
        var nums1 = IntArray(26)
        var nums2 = IntArray(26)
        for(i in 0 until patternsize){
            nums1[s1[i] - 'a']++
            nums2[s2[i] - 'a']++
        }
        if(compare(nums1,nums2)){
            return true
        }
        for(i in patternsize until n){
            nums2[s2[i] - 'a']++
            nums2[s2[i-patternsize] - 'a']--
            if(compare(nums1,nums2)){
                return true 
            }
        }
        return false
    }
    fun compare(nums1:IntArray,nums2:IntArray):Boolean{
        if(nums1.size != nums2.size || nums1 == null || nums2 == null){
            return false
        }
        for(i in 0 until nums1.size){
            if (nums1[i] != nums2[i]){
                return false
            }
        }
        return true
    }
}