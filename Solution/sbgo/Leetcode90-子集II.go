package sbgo

import "sort"

func subsetsWithDup(nums []int) (ans [][]int) {
	n := len(nums)
	path := []int{}
	used := make([]int, n)
	sort.Ints(nums)
	var dfs func(int, []int)
	dfs = func(index int, nums []int) {
		ans = append(ans, append([]int(nil), path...))
		for i := index; i < len(nums); i++ {
			if i > 0 && nums[i-1] == nums[i] && used[i-1] == 0 {
				continue
			}
			path = append(path, nums[i])
			used[i] = 1
			dfs(i+1, nums)
			path = path[:len(path)-1]
			used[i] = 0
		}
		return
	}
	dfs(0, nums)
	return
}
