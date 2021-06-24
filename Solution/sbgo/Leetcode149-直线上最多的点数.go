package sbgo

func maxPoints(points [][]int) int {
	res := 0
	for _, p := range points {
		dup, ver := 0, 0
		cnt := make(map[float64]int, 0)
		for _, q := range points {
			if p[0] == q[0] && p[1] == q[1] {
				dup++
			} else if p[0] == q[0] {
				ver++
			} else {
				k := float64((p[1] - q[1])) / float64((p[0] - q[0]))
				cnt[k]++
			}
		}
		cur := ver
		for _, t := range cnt {
			cur = max(cur, t)
		}
		res = max(res, cur+dup)
	}
	return res
}
