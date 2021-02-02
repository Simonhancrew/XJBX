package sbgo

func characterReplacement(s string, k int) int {
	n := len(s)
	nums := make([]int, 26)
	fast, slow := 0, 0
	maxn := 0
	for fast < n {
		nums[s[fast]-'A']++
		maxn = max(maxn, nums[s[fast]-'A'])
		if fast-slow+1-maxn > k {
			nums[s[slow]-'A']--
			slow++
		}
		fast++
	}
	return fast - slow
}
