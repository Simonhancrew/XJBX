package sbgo

//char是int32
//但byte能和uint8比较，不能和int32

func removeDuplicateLetters(s string) string {
	nums := [26]int{}
	for _, ch := range s {
		nums[ch-'a']++
	}
	stk := []byte{}
	used := [26]bool{}
	for _, ch := range s {
		if !used[ch-'a'] {
			for len(stk) > 0 && byte(ch) < stk[len(stk)-1] {
				last := stk[len(stk)-1] - 'a'
				if nums[last] == 0 {
					break
				}
				stk = stk[:len(stk)-1]
				used[last] = false
			}
			stk = append(stk, byte(ch))
			used[ch-'a'] = true
		}
		nums[ch-'a']--
	}
	return string(stk)
}
