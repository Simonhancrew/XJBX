package sbgo

func shipWithinDays(weights []int, D int) int {
	l, r := weights[0], 0
	for i := 0; i < len(weights); i++ {
		if l < weights[i] {
			l = weights[i]
		}
		r += weights[i]
	}
	possible := func(load int) bool {
		cur, res := 0, 0
		for i := 0; i < len(weights); i++ {
			if i != 0 && cur+weights[i] <= load {
				cur += weights[i]
			} else {
				res++
				cur = weights[i]
			}
		}
		if res <= D {
			return true
		}
		return false
	}
	for l < r {
		mid := (l + r) / 2
		if possible(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}
