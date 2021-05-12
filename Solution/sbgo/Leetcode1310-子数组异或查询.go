package sbgo

func xorQueries(arr []int, queries [][]int) []int {
	n := len(arr)
	ans := []int{}
	arr = append(arr, 0)
	for i := 1; i <= n; i++ {
		arr[i] ^= arr[i-1]
	}
	arr = append([]int{0}, arr...)
	for _, query := range queries {
		ans = append(ans, arr[query[1]+1]^arr[query[0]])
	}
	return ans
}

//go头部插入的方法

/*
	append([]int{1},nums)
	其中nums是一个slice，但是这么写是错误的，因为append第二个参数应该是一个参数，单这里传入了一个slice。
	将其改成append([]int{1},nums...)即可，差别仅仅是nums后面多了...这样就代表传入的是多个元素而不是一个slice，
	但是这样其实是把nums打散成多个元素然后挨个插入第一个slice中
*/
