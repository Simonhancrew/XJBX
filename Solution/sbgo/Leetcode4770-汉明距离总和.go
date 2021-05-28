package sbgo

func totalHammingDistance(nums []int) int {
	n, res := len(nums), 0
	for i := 0; i < 30; i++ {
		c := 0
		for _, num := range nums {
			if num>>i&1 == 1 {
				c++
			}
		}
		res += c * (n - c)
	}
	return res
}
