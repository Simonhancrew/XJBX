class KthLargest(k: Int, nums: IntArray) {
    val hp = PriorityQueue<Int>(){v1,v2->v1- v2}
    val k = k
    init {
        for (num in nums){
            hp.offer(num)
            if(hp.size > k){
                hp.poll()
            }
        }
    }
    fun add(`val`: Int): Int {
        hp.offer(`val`)
        if(hp.size > k){
            hp.poll()
        }
        return hp.peek()
    }
}