package sbgo

//用哈希表做不是最优
//全体异或，丢失的值最后会出现
func missingNumber(nums []int) int {
	n := len(nums)
	res := n
	for i := 0; i < n; i++ {
		res = res ^ i ^ nums[i]
	}
	return res
}
