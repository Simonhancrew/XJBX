package sbgo

func numEquivDominoPairs(dominoes [][]int) int {
	num := make([]int, 100) //map换成map[int]int{}
	ans := 0
	for _, it := range dominoes {
		val := 0
		if it[0] > it[1] {
			val = it[1]*10 + it[0]
		} else {
			val = it[0]*10 + it[1]
		}
		ans += num[val]
		num[val]++
	}
	return ans
}
