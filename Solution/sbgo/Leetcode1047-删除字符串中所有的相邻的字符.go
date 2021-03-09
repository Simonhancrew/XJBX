package sbgo

func removeDuplicates(S string) string {
	st := []rune{}
	for _, ch := range S {
		if len(st) != 0 && st[len(st)-1] == ch {
			st = st[:len(st)-1]
		} else {
			st = append(st, ch)
		}
	}
	res := string(st)
	return res
}
