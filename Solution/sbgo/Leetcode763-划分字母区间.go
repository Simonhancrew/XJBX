package sbgo

func partitionLabels(S string) []int {
	last := [26]int{}
	for i := range S {
		last[S[i]-'a'] = i
	}
	res := []int{}
	start, end := 0, 0
	for i := range S {
		end = max(end, last[S[i]-'a'])
		if i == end {
			res = append(res, end-start+1)
			start = end + 1
		}
	}
	return res
}
