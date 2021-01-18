package sbgo

import "sort"

func accountsMerge(accounts [][]string) [][]string {
	email2Index := make(map[string]int)
	email2Name := map[string]string{}
	for _, account := range accounts {
		name := account[0]
		for _, email := range account[1:] {
			if _, has := email2Index[email]; !has {
				email2Name[email] = name
				email2Index[email] = len(email2Index)
			}
		}
	}
	parent := make([]int, len(email2Index))
	for i := range parent {
		parent[i] = i
	}
	var find func(i int) int
	find = func(i int) int {
		if parent[i] == i {
			return i
		}
		parent[i] = find(parent[i])
		return parent[i]
	}
	union := func(x, y int) {
		fx, fy := find(x), find(y)
		if fx == fy {
			return
		}
		parent[fy] = fx
	}
	for _, account := range accounts {
		firstIndex := email2Index[account[1]]
		for _, email := range account[2:] {
			union(firstIndex, email2Index[email])
		}
	}
	index2Email := map[int][]string{}
	for email, index := range email2Index {
		index = find(index)
		index2Email[index] = append(index2Email[index], email)
	}
	ans := [][]string{}
	for _, emails := range index2Email {
		sort.Strings(emails)
		name := email2Name[emails[0]]
		cur := append([]string{name}, emails...)
		ans = append(ans, cur)
	}
	return ans
}
