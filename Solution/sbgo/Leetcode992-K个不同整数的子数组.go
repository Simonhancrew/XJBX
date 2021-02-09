package sbgo

func subarraysWithKDistinct(A []int, K int) int {
	n := len(A)
	start1, start2, end := 0, 0, 0
	total1, total2 := 0, 0
	nums1 := make([]int, n+1)
	nums2 := make([]int, n+1)
	ans := 0
	for end < n {
		if nums1[A[end]] == 0 {
			total1++
		}
		nums1[A[end]]++
		if nums2[A[end]] == 0 {
			total2++
		}
		nums2[A[end]]++
		for total1 > K {
			nums1[A[start1]]--
			if nums1[A[start1]] == 0 {
				total1--
			}
			start1++
		}
		for total2 > K-1 {
			nums2[A[start2]]--
			if nums2[A[start2]] == 0 {
				total2--
			}
			start2++
		}
		ans += start2 - start1
		end++
	}
	return ans
}
