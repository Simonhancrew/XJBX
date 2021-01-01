package sbgo

import "sort"

func groupAnagrams(strs []string) [][]string {
	//map需要创建 mp := map[string][]string{}
	var mp = make(map[string][]string)
	for _, i := range strs {
		//要修改字符串，需要先将其转换成rune或byte数组，字符串本身不能修改
		//如果有其余的文字的话要使用rune数组
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
