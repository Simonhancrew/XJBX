package sbgo

func maxScore(cardPoints []int, k int) int {
	n := len(cardPoints)
	windowSize := n - k
	sum := 0
	for _, val := range cardPoints[:windowSize] {
		sum += val
	}
	minSum := sum
	for i := windowSize; i < n; i++ {
		sum += (cardPoints[i] - cardPoints[i-windowSize])
		minSum = min(minSum, sum)
	}
	accu := 0
	for _, val := range cardPoints {
		accu += val
	}
	ans := accu - minSum
	return ans
}
