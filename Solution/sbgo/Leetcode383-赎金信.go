package sbgo

func canConstruct(ransomNote string, magazine string) bool {
	if len(magazine) < len(ransomNote) {
		return false
	}
	//'a'和ch都是int32
	words := [26]int{}
	for _, ch := range magazine {
		words[ch-'a']++
	}
	for _, ch := range ransomNote {
		words[ch-'a']--
		if words[ch-'a'] < 0 {
			return false
		}
	}
	return true
}
