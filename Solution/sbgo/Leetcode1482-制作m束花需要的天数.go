package sbgo

//tle
func minDays(bloomDay []int, m int, k int) int {
	if k*m > len(bloomDay) {
		return -1
	}
	check := func(day int) bool {
		flowers, bqt := 0, 0
		for _, bloom := range bloomDay {
			if bloom <= day {
				flowers++
				if flowers == k {
					bqt++
					if bqt == m {
						return true
					}
					flowers = 0
				}
			} else {
				flowers = 0
			}
		}
		return bqt == m
	}
	l, r := bloomDay[0], bloomDay[0]
	for _, b := range bloomDay {
		if b > r {
			r = b
		}
		if l < b {
			l = b
		}
	}
	for l < r {
		mid := l + r>>1
		if check(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	if !check(l) {
		l = -1
	}
	return l
}

/*
func minDays(bloomDay []int, m, k int) int {
    if k*m > len(bloomDay) {
        return -1
    }
    maxDay := 0
    for _, day := range bloomDay {
        if day > maxDay {
            maxDay = day
        }
    }
    return sort.Search(maxDay, func(days int) bool {
        flowers, bouquets := 0, 0
        for _, d := range bloomDay {
            if d > days {
                flowers = 0
            } else {
                flowers++
                if flowers == k {
                    bouquets++
                    flowers = 0
                }
            }
        }
        return bouquets >= m
    })
}
*/
