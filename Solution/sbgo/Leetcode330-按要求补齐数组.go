package sbgo

func minPatches(nums []int, n int) int {
	res := 0
	index := 0
	cover := 1
	length := len(nums)
	for cover <= n {
		if index < length && cover >= nums[index] {
			cover += nums[index]
			index++
		} else {
			res++
			cover <<= 1
		}
	}
	return res
}
