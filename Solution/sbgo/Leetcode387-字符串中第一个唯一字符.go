package sbgo

func firstUniqChar(s string) int {
	mp := [26]int{}
	for _, val := range s {
		mp[val-'a']++
	}
	for i := range s {
		if mp[s[i]-'a'] == 1 {
			return i
		}
	}
	return -1
}
