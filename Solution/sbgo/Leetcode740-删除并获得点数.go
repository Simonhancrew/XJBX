package sbgo

func deleteAndEarn(nums []int) int {
	maxV := nums[0]
	for i := range nums {
		maxV = max(nums[i], maxV)
	}
	sum := make([]int, maxV+1)
	for _, num := range nums {
		sum[num] += num
	}
	old, now := sum[0], sum[1]
	for i := 3; i <= maxV+1; i++ {
		tmp := max(old+sum[i-1], now)
		old = now
		now = tmp
	}
	return now
}
