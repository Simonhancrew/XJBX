package sbgo

func singleNumber(nums []int) int {
	hash := map[int]int{}
	for _, num := range nums {
		hash[num]++
	}
	ans := 0
	for k, v := range hash {
		if v == 1 {
			ans = k
			break
		}
	}
	return ans
}
