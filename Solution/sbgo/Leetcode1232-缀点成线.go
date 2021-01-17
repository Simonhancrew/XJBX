package sbgo

func checkStraightLine(coordinates [][]int) bool {
	offsetX, offsetY := coordinates[0][0], coordinates[0][1]
	n := len(coordinates)
	for i := range coordinates {
		coordinates[i][0] -= offsetX
		coordinates[i][1] -= offsetY
	}
	A, B := coordinates[1][1], -coordinates[1][0]
	for i := 2; i < n; i++ {
		if A*coordinates[i][0]+B*coordinates[i][1] != 0 {
			return false
		}
	}
	return true
}
