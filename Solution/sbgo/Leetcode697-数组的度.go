package sbgo

func findShortestSubArray(nums []int) int {
	mp := make(map[int][]int)
	for i, num := range nums {
		if array, has := mp[num]; has {
			array[0]++
			array[2] = i
		} else {
			mp[num] = []int{1, i, i}
		}
	}
	ans, maxnum := 0, 0
	for _, array := range mp {
		if array[0] > maxnum {
			ans = array[2] - array[1] + 1
			maxnum = array[0]
		} else if maxnum == array[0] {
			if ans > array[2]-array[1]+1 {
				ans = array[2] - array[1] + 1
			}
		}
	}
	return ans
}
