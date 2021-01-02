package sbgo

//时间复杂度是k，k是二进制中1的个数

func hammingWeight(num uint32) int {
	count := 0
	for num != 0 {
		count++
		num &= (num - 1)
	}
	return count
}
