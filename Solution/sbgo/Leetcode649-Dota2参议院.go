package sbgo

//贪心，先灭掉前面的
//用队列模拟循环，push入坐标
//比对队列头的大小，小的更具有优势，pop掉大的
//最后队列中还有值的就是结果
func predictPartyVictory(senate string) string {
	var radiant, dire []int
	for i, j := range senate {
		if j == 'R' {
			radiant = append(radiant, i)
		} else {
			dire = append(dire, i)
		}
	}

	for len(dire) > 0 && len(radiant) > 0 {
		if dire[0] < radiant[0] {
			dire = append(dire, dire[0]+len(senate))
		} else {
			radiant = append(radiant, radiant[0]+len(senate))
		}
		dire = dire[1:]
		radiant = radiant[1:]
	}
	if len(radiant) > 0 {
		return "Radiant"
	} else {
		return "Dire"
	}
}
