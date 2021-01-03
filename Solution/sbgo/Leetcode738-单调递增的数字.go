package sbgo

import "strconv"

//对于一个数，把它变成字符串，然后找到递增的前半部分
//之后将最后一个char减一，之后的全部变成9
//就的到一个最大递增数
func monotoneIncreasingDigits(N int) int {
	//string无法修改，改成底层的byte数组
	s := []byte(strconv.Itoa(N))
	var n = len(s)
	t := n
	//为什么从后往前？332，从前往后会影响之前的状态
	//329，不符合要变成299
	//这也符合处理的逻辑，从低位考虑到高位
	for i := n - 1; i >= 1; i-- {
		if s[i-1] > s[i] {
			t = i
			s[i-1]--
		}
	}
	for t < n {
		s[t] = '9'
		t++
	}
	//second var is nil or nor nil to judge success
	res, _ := strconv.Atoi(string(s))
	return res
}
