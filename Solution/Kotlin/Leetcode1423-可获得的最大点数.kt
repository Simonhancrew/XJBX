class Solution {
    fun maxScore(cardPoints: IntArray, k: Int): Int {
        val length = cardPoints.size
        val windowsize = length - k
        var sum = 0
        for (i in 0 until windowsize){
            sum += cardPoints[i]
        }
        var minsum = sum
        for (i in windowsize until length){
            sum = sum + cardPoints[i] - cardPoints[i - windowsize]
            minsum = Math.min(minsum,sum)
        }
        var total = 0
        for (i in cardPoints){
            total += i
        }
        return total - minsum
    }
}