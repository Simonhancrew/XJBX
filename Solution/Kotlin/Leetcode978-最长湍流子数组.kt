class Solution {
    fun maxTurbulenceSize(arr: IntArray): Int {
        val n = arr.size
        var start = 0
        var end = 1
        var ans = 1
        var direction = false   
        while(end < n){
            if(end == start + 1){
                if(arr[end - 1] > arr[end]){
                    direction = true
                    ans = Math.max(ans,2)
                }else if(arr[end - 1] < arr[end]){
                    direction = false
                    ans = Math.max(ans,2)
                }else{
                    start++
                }
                end++
            }else{
                if((arr[end - 1] > arr[end] && !direction) ||(arr[end - 1] < arr[end] && direction)){
                    ans = Math.max(ans,end - start + 1)
                    end++
                    direction = !direction
                }else{
                    start = end - 1
                }
            }
        }
        return ans
    }
}