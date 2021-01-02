package sbgo

import "sort"

func eraseOverlapIntervals(intervals [][]int) int {
	if len(intervals) == 0 {
		return 0
	}
	//按照右边界排序，贪心的找下一个不重叠的区间
	//因为下一个区间也是按照右边界排序的，所以肯定是一个短区间
	//找到不重叠的区间之后用总区间数减就可以得到删除区间
	sort.Slice(intervals, func(i, j int) bool { return intervals[i][1] < intervals[j][1] })
	cnt := 1
	curborder := intervals[0][1]
	for _, val := range intervals[1:] {
		if val[0] >= curborder {
			curborder = val[1]
			cnt++
		}
	}
	return len(intervals) - cnt
}
