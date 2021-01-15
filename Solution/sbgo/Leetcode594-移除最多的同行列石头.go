package sbgo

func removeStones(stones [][]int) int {
	n := len(stones)
	rec := make(map[int][]int)
	//记录一下每行列中有那些石头
	for i, stone := range stones {
		rec[stone[0]] = append(rec[stone[0]], i)
		rec[stone[1]+10001] = append(rec[stone[1]+10001], i)
	}
	edges := make(map[int][]int)
	for _, val := range rec {
		k := len(val)
		for i := 1; i < k; i++ {
			edges[val[i-1]] = append(edges[val[i-1]], val[i])
			edges[val[i]] = append(edges[val[i]], val[i-1])
		}
	}
	vis := make([]int, n)
	var df func(i int)
	df = func(i int) {
		vis[i] = 1
		for _, val := range edges[i] {
			if vis[val] == 0 {
				vis[val] = 1
				df(val)
			}
		}
	}
	num := 0
	for i := range stones {
		if vis[i] == 0 {
			num++
			df(i)
		}
	}
	return n - num
}
