package sbgo

func maxArea(height []int) int {
	i, j := 0, len(height)-1
	res := 0
	for i < j {
		cur := min(height[i], height[j]) * (j - i)
		res = max(res, cur)
		if height[i] > height[j] {
			j--
		} else {
			i++
		}
	}
	return res
}
