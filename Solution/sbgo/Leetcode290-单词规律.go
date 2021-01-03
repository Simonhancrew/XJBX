package sbgo

import "strings"

//做两个map，完成一个双映射的
//split空格，不用考虑index的问题
func wordPattern(pattern string, s string) bool {
	str2chr := make(map[string]byte)
	chr2str := make(map[byte]string)
	words := strings.Split(s, " ")
	if len(words) != len(pattern) {
		return false
	}
	for index, str := range words {
		ch := pattern[index]
		if str2chr[str] != 0 && str2chr[str] != ch || chr2str[ch] != "" && chr2str[ch] != str {
			return false
		}
		str2chr[str] = ch
		chr2str[ch] = str
	}
	return true
}
