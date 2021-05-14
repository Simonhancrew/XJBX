package sbgo

var hh = []struct {
	l int
	r string
}{
	{1000, "M"},
	{900, "CM"},
	{500, "D"},
	{400, "CD"},
	{100, "C"},
	{90, "XC"},
	{50, "L"},
	{40, "XL"},
	{10, "X"},
	{9, "IX"},
	{5, "V"},
	{4, "IV"},
	{1, "I"},
}

func intToRoman(num int) string {
	var res []byte
	for _, h := range hh {
		for num >= h.l {
			num -= h.l
			res = append(res, h.r...)
		}
		if num == 0 {
			break
		}
	}
	return string(res)
}
