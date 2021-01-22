package sbgo

func addToArrayForm(A []int, K int) []int {
	n := len(A)
	res := []int{}
	for i:=n-1;i >= 0;i--{
		sum := A[i] + K %10
		K = K / 10
		if sum >= 10{
			sum -= 10
			K++
		}
		res = append(res,sum)
	}
	for K > 0{
		res = append(res,K % 10)
		K = K / 10
	}
	reverse(res)
	return res
}

func reverse(A []int) {
    for i, n := 0, (len(A)-1); i <= n; {
        A[i], A[n] = A[n], A[i]
        i++
        n--
    }
}
