package sbgo

func twoSum(nums []int, target int) []int {
	mp := map[int]int{}
	for i, val := range nums {
		need := target - val //拿到需要去查有没有的数
		//如何去查一张哈希表
		if index, ok := mp[need]; ok {
			return []int{i, index}
		}
		mp[val] = i
	}
	return nil
}
