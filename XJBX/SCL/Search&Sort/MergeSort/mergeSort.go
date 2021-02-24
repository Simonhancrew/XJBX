package main

import (
	"fmt"
)

func mergeSort(input []int) {
	if len(input) <= 1 {
		return
	}
	mid := len(input) / 2
	//go里的深拷贝，先创建内存空间再去copy
	L := make([]int, len(input[:mid]))
	R := make([]int, len(input[mid:]))
	copy(L, input[:mid])
	copy(R, input[mid:])
	mergeSort(L)
	mergeSort(R)
	i, j, k := 0, 0, 0
	for i < len(L) && j < len(R) {
		if L[i] <= R[j] {
			input[k] = L[i]
			i++
		} else {
			input[k] = R[j]
			j++
		}
		k++
	}
	for i < len(L) {
		input[k] = L[i]
		i++
		k++
	}
	for j < len(R) {
		input[k] = R[j]
		k++
		j++
	}
}

func main() {
	input := []int{3, 1}
	mergeSort(input)
	for _, val := range input {
		fmt.Println(val)
	}
}
