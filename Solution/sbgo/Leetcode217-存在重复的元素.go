package sbgo

//set的map实现
func containsDuplicate(nums []int) bool {
	set := make(map[int]struct{})
	for _, v := range nums {
		if _, has := set[v]; has {
			return true
		}
		set[v] = struct{}{}
	}
	return false
}
