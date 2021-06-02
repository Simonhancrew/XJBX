package sbgo

func checkSubarraySum(nums []int, k int) bool {
	n := len(nums)
	if n < 2 {
		return false
	}
	re := 0
	mp := map[int]int{}
	mp[0] = -1
	for i := 0; i < n; i++ {
		re = (re + nums[i]) % k
		if idx, has := mp[re]; has {
			if i-idx >= 2 {
				return true
			}
		} else {
			mp[re] = i
		}
	}
	return false
}
