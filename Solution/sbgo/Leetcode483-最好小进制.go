package sbgo

import (
	"math"
	"strconv"
)

func smallestGoodBase(n string) string {
	N, _ := strconv.Atoi(n)
	for t := int(math.Log2(float64(N))) + 1; t >= 3; t-- {
		k := int(math.Pow(float64(N), 1.0/(float64(t)-1)))
		r := 0
		for i := 0; i < t; i++ {
			r = r*k + 1
		}
		if r == N {
			return strconv.Itoa(k)
		}
	}
	return strconv.Itoa(N - 1)
}
