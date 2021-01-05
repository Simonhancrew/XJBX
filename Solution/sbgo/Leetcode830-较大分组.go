package sbgo

func largeGroupPositions(s string) [][]int {
	start := 0
	end := 0
	n := len(s)
	var res [][]int
	for end < n {
		if s[start] == s[end] {
			end++
		} else {
			length := end - start
			if length >= 3 {
				res = append(res, []int{start, end - 1})
			}
			start = end
		}
	}
	if end-start >= 3 {
		res = append(res, []int{start, end - 1})
	}
	return res
}
