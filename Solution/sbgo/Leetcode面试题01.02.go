package sbgo

//一个哈希映射

func CheckPermutation(s1 string, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}
	used := [26]int{}
	for i := range s1 {
		used[s1[i]-'a']++
	}
	for i := range s2 {
		used[s2[i]-'a']--
		if used[s2[i]-'a'] < 0 {
			return false
		}
	}
	return true
}
