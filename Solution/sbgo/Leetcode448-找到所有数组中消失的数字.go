package sbgo

func findDisappearedNumbers(nums []int) []int {
	n := len(nums)
	for _, val := range nums {
		x := (val - 1) % n
		nums[x] += n
	}
	ans := []int{}
	for i := range nums {
		if nums[i] <= n {
			ans = append(ans, i+1)
		}
	}
	return ans
}
