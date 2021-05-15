package sbgo

func findMaximumXOR(nums []int) int {
	ans := 0
	for i := 30; i >= 0; i-- {
		st := map[int]bool{}
		for _, num := range nums {
			st[num>>i] = true
		}
		nex := ans*2 + 1
		fd := false
		for pre := range st {
			if st[pre^nex] {
				fd = true
				break
			}
		}
		if fd {
			ans = nex
		} else {
			ans = nex - 1
		}
	}
	return ans
}
