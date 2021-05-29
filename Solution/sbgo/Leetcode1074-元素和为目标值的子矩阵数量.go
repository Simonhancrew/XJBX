package sbgo

func numSubmatrixSumTarget(matrix [][]int, target int) int {
	ans, n, m := 0, len(matrix), len(matrix[0])
	count := func(presum []int, target int) int {
		res, cur := 0, 0
		mp := map[int]int{}
		mp[0] = 1
		for i := 0; i < len(presum); i++ {
			cur += presum[i]
			cnt, ok := mp[cur-target]
			if ok {
				res += cnt
			}
			mp[cur]++
		}
		return res
	}
	for i := 0; i < n; i++ {
		presum := make([]int, m)
		for j := i; j < n; j++ {
			for k := 0; k < m; k++ {
				presum[k] += matrix[j][k]
			}
			ans += count(presum, target)
		}
	}
	return ans
}
