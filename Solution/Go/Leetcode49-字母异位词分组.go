package Go

import "sort"

func groupAnagrams(strs []string) [][]string {
	//map需要创建 mp := map[string][]string{}
	var mp = make(map[string][]string)
	for _, i := range strs {
		key := []byte(i)
		sort.Slice(key, func(i, j int) bool { return key[i] < key[j] })
		sortedStr := string(key)
		mp[sortedStr] = append(mp[sortedStr], i)
	}
	var ans [][]string
	for _, j := range mp {
		ans = append(ans, j)
	}
	return ans
}
