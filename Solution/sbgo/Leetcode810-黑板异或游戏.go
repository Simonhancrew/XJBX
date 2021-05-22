package sbgo

func xorGame(nums []int) bool {
	if len(nums)%2 == 0 {
		return true
	}
	res := 0
	for _, num := range nums {
		res ^= num
	}
	return res == 0
}
