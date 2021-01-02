package sbgo

import "sort"

func findMinArrowShots(points [][]int) int {
	if len(points) == 0 {
		return 0
	}
	sort.Slice(points, func(i, j int) bool { return points[i][1] < points[j][1] })
	leftBorder := points[0][1]
	ans := 1
	for _, i := range points {
		if i[0] > leftBorder {
			ans++
			leftBorder = i[1]
		}
	}
	return ans
}
