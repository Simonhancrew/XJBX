package sbgo

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	n := min(numRows, len(s))
	row := make([][]byte, n)
	curRow := 0
	goDown := false
	for _, ch := range s {
		row[curRow] = append(row[curRow], byte(ch))
		if curRow == 0 || curRow == numRows-1 {
			goDown = !goDown
		}
		if goDown {
			curRow++
		} else {
			curRow--
		}
	}
	//我尝试过字符串+=，但是没有byte下append快，不知道为啥？
	var res []byte
	for _, i := range row {
		for _, j := range i {
			res = append(res, j)
		}
	}
	return string(res)
}
