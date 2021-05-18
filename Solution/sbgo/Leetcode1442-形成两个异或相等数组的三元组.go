package sbgo

func countTriplets(arr []int) int {
	n := len(arr)
	presum := make([]int, n+1)
	for i := 0; i < n; i++ {
		presum[i+1] = presum[i] ^ arr[i]
	}
	res := 0
	for i := 0; i < n; i++ {
		for k := i + 1; k < n; k++ {
			if presum[i] == presum[k+1] {
				res += k - i
			}
		}
	}
	return res
}
