package sbgo

func maxTurbulenceSize(arr []int) int {
	n := len(arr)
	start, end := 0, 1
	direction := false
	ans := 1
	for end < n {
		if start+1 == end {
			if arr[end-1] > arr[end] {
				direction = true
				ans = max(ans, 2)
			} else if arr[end-1] < arr[end] {
				direction = false
				ans = max(ans, 2)
			} else {
				start++
			}
			end++
		} else {
			if (arr[end-1] > arr[end] && !direction) || (arr[end-1] < arr[end] && direction) {
				ans = max(ans, end-start+1)
				end++
				direction = !direction
			} else {
				start = end - 1
			}

		}
	}
	return ans
}
