package sbgo

func openLock(deadends []string, target string) int {
	start := "0000"
	if start == target {
		return 0
	}
	lock := map[string]bool{}
	for _, s := range deadends {
		lock[s] = true
	}
	if _, ok := lock[start]; ok {
		return -1
	}
	dist := map[string]int{}
	dist[start] = 0
	que := make([]string, 0)
	que = append(que, start)
	for len(que) > 0 {
		t := que[0]
		que = que[1:]
		for i := 0; i < 4; i++ {
			for j := -1; j < 2; j += 2 {
				st := []byte(t)
				st[i] = byte((int(st[i])-int('0')+j+10)%10) + byte('0')
				if _, ok := dist[string(st)]; !ok {
					if _, ok := lock[string(st)]; !ok {
						dist[string(st)] = dist[t] + 1
						if string(st) == target {
							return dist[string(st)]
						}
						que = append(que, string(st))
					}
				}
			}
		}
	}
	return -1
}
