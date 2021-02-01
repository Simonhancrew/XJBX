package sbgo

func fairCandySwap(A []int, B []int) []int {
	suma, sumb := 0, 0
	mp := make(map[int]int)
	for _, a := range A {
		suma += a
		mp[a]++
	}
	for _, b := range B {
		sumb += b
	}
	want := (suma - sumb) / 2
	for _, b := range B {
		if _, err := mp[want+b]; err != false {
			return []int{want + b, b}
		}
	}
	return []int{}
}
