package sbgo

func findErrorNums(nums []int) []int {
	n := len(nums)
	dt := make([]int, n+1)
	ans := []int{}
	for _, num := range nums {
		dt[num]++
		if dt[num] > 1 {
			ans = append(ans, num)
		}
	}
	for i := 1; i <= n; i++ {
		if dt[i] == 0 {
			ans = append(ans, i)
			break
		}
	}
	return ans
}
