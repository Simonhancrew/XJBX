package sbgo

func leastBricks(wall [][]int) int {
	hash := map[int]int{}
	for _, line := range wall {
		s := 0
		for i := 0; i < len(line)-1; i++ {
			s += line[i]
			hash[s]++
		}
	}
	res := 0
	for _, v := range hash {
		res = max(res, v)
	}
	return len(wall) - res
}
