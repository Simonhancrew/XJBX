package sbgo

func isMonotonic(A []int) bool {
	n := len(A)
	inc, dec := true, true
	for i := 0; i < n-1; i++ {
		if A[i] > A[i+1] {
			inc = false
		}
		if A[i] < A[i+1] {
			dec = false
		}
	}
	return inc || dec
}
