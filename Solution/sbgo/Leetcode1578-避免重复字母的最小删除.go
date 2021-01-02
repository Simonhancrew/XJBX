package sbgo

//确定不变量，保留一个i去遍历一个字符串，利用这个i去处理重复的

func minCost(s string, cost []int) int {
	n := len(s)
	i := 0
	res := 0
	for i < n {
		ch := s[i]
		sum := 0
		maxv := 0
		for i < n && ch == s[i] {
			maxv = max(maxv, cost[i])
			sum += cost[i]
			i++
		}
		res += (sum - maxv)
	}
	return res
}
