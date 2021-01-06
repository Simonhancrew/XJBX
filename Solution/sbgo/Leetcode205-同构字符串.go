package sbgo

func isIsomorphic(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	s2t := make(map[byte]byte)
	t2s := make(map[byte]byte)
	for i, ch := range s {
		if s2t[byte(ch)] != 0 && byte(s2t[byte(ch)]) != t[i] {
			return false
		}
		if t2s[byte(t[i])] != 0 && byte(t2s[byte(t[i])]) != byte(ch) {
			return false
		}
		s2t[byte(ch)] = byte(t[i])
		t2s[byte(t[i])] = byte(ch)
	}
	return true
}
