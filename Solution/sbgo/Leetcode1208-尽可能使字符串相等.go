package sbgo

func equalSubstring(s string, t string, maxCost int) int {
	ans := 0
	start, end := 0, 0
	cost := 0
	length := len(s)
	for end < length {
		cost += abs(int(s[end]) - int(t[end]))
		for cost > maxCost {
			cost -= abs(int(s[start]) - int(t[start]))
			start++
		}
		ans = max(ans, end-start+1)
		end++
	}
	return ans
}
