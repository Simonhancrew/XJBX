package sbgo

func toHex(num int) string {
	pattern := "0123456789abcdef"
	shift := 0
	mod := 0xf
	var ans string
	if num == 0 {
		return "0"
	}
	for num != 0 && shift < 8 {
		index := num & mod
		ans = string(pattern[index]) + ans
		num >>= 4
		shift++
	}
	return ans
}
