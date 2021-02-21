package sbgo

func longestSubarray(nums []int, limit int) int {
	minlist, maxlist := []int{}, []int{}
	n := len(nums)
	left := 0
	ans := 0
	for right := 0; right < n; right++ {
		for len(minlist) > 0 && minlist[len(minlist)-1] > nums[right] {
			minlist = minlist[:len(minlist)-1]
		}
		for len(maxlist) > 0 && maxlist[len(maxlist)-1] < nums[right] {
			maxlist = maxlist[:len(maxlist)-1]
		}
		maxlist = append(maxlist, nums[right])
		minlist = append(minlist, nums[right])
		for len(minlist) > 0 && len(maxlist) > 0 && maxlist[0]-minlist[0] > limit {
			if minlist[0] == nums[left] {
				minlist = minlist[1:]
			}
			if maxlist[0] == nums[left] {
				maxlist = maxlist[1:]
			}
			left++
		}
		ans = max(ans, right-left+1)
	}
	return ans
}
