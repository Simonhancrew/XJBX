package sbgo

func findMaxLength(nums []int) int {
	n, ans, cur := len(nums), 0, 0
	mp := map[int]int{}
	mp[0] = -1
	cnt := 0
	for i := 0; i < n; i++ {
		if nums[i] == 1 {
			cur = 1
		} else {
			cur = -1
		}
		cnt += cur
		if idx, has := mp[cnt]; has {
			ans = max(ans, i-idx)
		} else {
			mp[cnt] = i
		}
	}
	return ans
}
