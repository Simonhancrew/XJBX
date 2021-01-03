package sbgo

func lemonadeChange(bills []int) bool {
	var five = 0
	var ten = 0
	n := len(bills)
	if n == 0 {
		return true
	}
	for _, value := range bills {
		if value == 5 {
			five++
		} else if value == 10 {
			if five < 1 {
				return false
			} else {
				five--
				ten++
			}
		} else {
			if five > 0 && ten > 0 {
				five--
				ten--
			} else if five >= 3 {
				five -= 3
			} else {
				return false
			}
		}
	}
	return true
}
