package sbgo

import "sort"

//重新排序，按左端从小到大。之后找他的右端点是否和下一个区间有重合，是的话就覆盖
//反之就直接加answer入区间中

func merge(intervals [][]int) [][]int {
	ans := [][]int{}
	n := len(intervals)
	if n == 0 {
		return ans
	}
	sort.Slice(intervals, func(i, j int) bool { return intervals[i][0] < intervals[j][0] })
	ans = append(ans, intervals[0])
	for i := 1; i < n; i++ {
		if ans[len(ans)-1][1] >= intervals[i][0] {
			ans[len(ans)-1][1] = max(ans[len(ans)-1][1], intervals[i][1])
		} else {
			ans = append(ans, intervals[i])
		}
	}
	return ans
}
