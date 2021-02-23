package sbgo

func maxSatisfied(customers []int, grumpy []int, X int) int {
	n := len(customers)
	init := 0
	for i := 0; i < n; i++ {
		if grumpy[i] == 0 {
			init += customers[i]
		}
	}
	increase := 0
	for i := 0; i < X; i++ {
		increase += grumpy[i] * customers[i]
	}
	maxIncrease := increase
	for i := X; i < n; i++ {
		increase += customers[i]*grumpy[i] - customers[i-X]*grumpy[i-X]
		maxIncrease = max(increase, maxIncrease)
	}
	return maxIncrease + init
}
