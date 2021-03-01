package sbgo

type NumArray struct {
	sum []int
}

func Constructor(nums []int) NumArray {
	sum := make([]int, len(nums)+1)
	for i, v := range nums {
		sum[i+1] = sum[i] + v
	}
	return NumArray{sum: sum}
}

func (this *NumArray) SumRange(i int, j int) int {
	return this.sum[j+1] - this.sum[i]
}
