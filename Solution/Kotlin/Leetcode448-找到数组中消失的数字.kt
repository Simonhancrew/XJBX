class Solution {
    fun findDisappearedNumbers(nums: IntArray): List<Int> {
        val n = nums.size
        for (num in nums){
            val x = (num - 1) % n
            nums[x] += n
        }
        val res = ArrayList<Int>()
        for(i in nums.indices){
            if(nums[i] <= n){
                res.add(i+1)
            }
        }
        return res
    }
}