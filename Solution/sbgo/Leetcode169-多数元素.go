package sbgo

// func majorityElement(nums []int) int {
// 	sort.Slice(nums, func(i, j int) bool { return nums[i] < nums[j] })
// 	return nums[len(nums)/2]
// }

//时间复杂度n，无额外的空间复杂度
//摩尔投票计数法用于选取多数元素
func majorityElement(nums []int) int {
	cur, count := nums[0], 1
	for i := 1; i < len(nums); i++ {
		if count == 0 {
			cur = nums[i]
			count = 1
		} else if cur == nums[i] {
			count++
		} else {
			count--
		}
	}
	return cur
}
