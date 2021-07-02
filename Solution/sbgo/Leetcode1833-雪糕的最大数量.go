package sbgo

import "sort"

func maxIceCream(costs []int, coins int) int {
	sort.Ints(costs)
	ans, i := 0, 0
	for i < len(costs) && coins >= costs[i] {
		coins -= costs[i]
		ans++
		i++
	}
	return ans
}
