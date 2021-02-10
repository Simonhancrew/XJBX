package sbgo

func checkInclusion(s1 string, s2 string) bool {
	pattersize, n := len(s1), len(s2)
	if n < pattersize {
		return false
	}
	nums1, nums2 := [26]int{}, [26]int{}
	for i := range s1 {
		nums1[s1[i]-'a']++
		nums2[s2[i]-'a']++
	}
	//slice不能比较，但是数组可以比较
	if nums1 == nums2 {
		return true
	}
	for i := pattersize; i < n; i++ {
		nums2[s2[i]-'a']++
		nums2[s2[i-pattersize]-'a']--
		if nums1 == nums2 {
			return true
		}
	}
	return false
}
