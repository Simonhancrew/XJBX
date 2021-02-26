package main

import "fmt"

func quickSort(input []int, l,r int){
	if l >= r{
		return 
	}
	i,j,x := l - 1,r + 1,input[l]
	for i < j{
		i++
		for input[i] < x{
			i++
		}
		j--
		for input[j] > x{
			j--
		}
		if i < j{
			input[i],input[j] = input[j],input[i]
		}
	}
	quickSort(input,l,j)
	quickSort(input,j+1,r)
}

func main()  {
	input := []int{2,2,1,4,5}
	quickSort(input,0,len(input) -1)
	for i := range(input){
		fmt.Println(input[i])
	}
}