package sbgo

func canPlaceFlowers(flowerbed []int, n int) bool {
	count := 0
	end := len(flowerbed)
	for i, val := range flowerbed {
		if val == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == end-1 || flowerbed[i+1] == 0) {
			// val = 1
			//此处不能修改val，要修改原slice
			flowerbed[i] = 1
			count++
		}
	}
	return count >= n
}
