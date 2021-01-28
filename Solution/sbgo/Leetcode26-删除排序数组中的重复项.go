package sbgo

func removeDuplicates(nums []int) int {
	slow, fast := 0, 0
	n := len(nums)
	if n == 0 {
		return 0
	}
	for fast < n {
		if nums[fast] == nums[slow] {
			fast++
		} else {
			slow++
			nums[fast], nums[slow] = nums[slow], nums[fast]
			fast++
		}
	}
	nums = nums[:slow+1]
	return slow + 1
}
