package sbgo

//暴力解
func canCompleteCircuit(gas []int, cost []int) int {
	for i := 0; i < len(gas); i++ {
		rest := gas[i] - cost[i]
		index := (i + 1) % len(gas)
		for rest > 0 && index != i {
			rest += gas[index] - cost[index]
			index = (index + 1) % len(gas)
		}
		if rest >= 0 && index == i {
			return i
		}
	}
	return -1
}

//贪心
func canCompleteCircuit2(gas []int, cost []int) int {
	start := 0
	var curSum, totalSum int
	for i := 0; i < len(gas); i++ {
		curSum += gas[i] - cost[i]
		totalSum += gas[i] - cost[i]
		if curSum < 0 {
			start = i + 1
			curSum = 0
		}
	}
	if totalSum < 0 {
		return -1
	}
	return start
}
