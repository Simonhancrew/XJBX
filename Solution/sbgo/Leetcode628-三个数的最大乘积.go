package sbgo

import (
	"sort"
	"math"
)

func maximumProduct(nums []int) int {
	sort.Slice(nums,func(i,j int) bool {return nums[i] < nums[j]})
	n := len(nums)
	return max(nums[0] * nums[1] * nums[n-1],nums[n-3]*nums[n-2]*nums[n-1])
}


func maximumProduct2(nums []int) int {
	min1,min2 := math.MaxInt64,math.MaxInt64
	max1,max2,max3 := math.MinInt64,math.MinInt64,math.MinInt64

	for _,num := range nums{
		if num < min1{
			min2 = min1
			min1 = num
		}else if num < min2 {
			min2 = num
		}

		if num > max1{
			max3 = max2 
			max2 = max1
			max1 = num
		}else if num > max2{
			max3 = max2
			max2 = num
		}else if num > max3{
			max3 = num
		}
	}
	return max(max1 * max2 * max3,min1 * min2 * max1)
}