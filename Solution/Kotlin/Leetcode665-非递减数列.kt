class Solution {
    fun checkPossibility(nums: IntArray): Boolean {
        val n = nums.size
        var cnt = 0
        for (i in 0 until n-1){
            val x = nums[i]
            val y= nums[i+1]
            if(x > y){
                cnt++
                if(cnt > 1){
                    return false    
                }
                if(i > 0 && nums[i+1] < nums[i-1]){
                    nums[i+1] = nums[i]
                }
            } 
        }
        return true
    }
}