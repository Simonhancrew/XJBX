package sbgo

import "sort"

func splitArraySameAverage(A []int) bool {
	size := len(A)
	sum := 0
	for _, value := range A {
		sum += value
	}
	sort.Slice(A, func(i, j int) bool { return A[i] < A[j] })
	//较短数组的长度
	for i := 1; i <= size/2; i++ {
		if sum*i%size == 0 && dfs(0, size, i, sum*i/size, A) == true {
			return true
		}
	}
	return false
}

func dfs(start, size, cnt, target int, A []int) bool {
	if cnt == 0 {
		return target == 0
	}
	for i := start; i < size-cnt+1; i++ {
		if size-start-1 < cnt {
			break
		}
		if i != start && A[i-1] == A[i] {
			continue
		}
		if dfs(i+1, size, cnt-1, target-A[i], A) {
			return true
		}
	}
	return false
}
