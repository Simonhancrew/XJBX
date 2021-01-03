package sbgo

func candy(ratings []int) int {
	n := len(ratings)
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = 1
		if i == 0 {
			continue
		}
		if ratings[i] > ratings[i-1] {
			res[i] = res[i-1] + 1
		}
	}
	for i := n - 2; i >= 0; i-- {
		if ratings[i] > ratings[i+1] {
			res[i] = max(res[i], res[i+1]+1)
		}
	}
	ans := 0
	for _, j := range res {
		ans += j
	}
	return ans
}
