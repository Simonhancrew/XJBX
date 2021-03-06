package sbgo

func rob(nums []int) int {
	n := len(nums)
	if n == 0 {
		return 0
	}
	if n == 1 {
		return nums[0]
	}
	rangeRob := func(nums []int, start, end int) int {
		if start == end {
			return nums[start]
		}
		dp := make([]int, len(nums))
		dp[start] = nums[start]
		dp[start+1] = max(nums[start], nums[start+1])
		for i := 2; i <= end; i++ {
			dp[i] = max(dp[i-1], dp[i-2]+nums[i])
		}
		return dp[end]
	}

	res1 := rangeRob(nums, 0, n-2)
	res2 := rangeRob(nums, 1, n-1)

	return max(res1, res2)
}

/*
func rob(nums []int) int {
    n:= len(nums)
    if n == 0 {
        return 0
    }
    if n == 1{
        return nums[0]
    }
    if n == 2{
        return max(nums[0],nums[1])
    }
    old,now := 0,nums[0]
    for i:=2;i < n;i++{
        t := now
        now = max(now,old + nums[i - 1])
        old = t
    }
    res := now
    old,now = 0,nums[1]
    for i := 2;i < n;i++{
        t := now
        now = max(now,old + nums[i])
        old = t
    }
    return max(now,res)
}
*/
