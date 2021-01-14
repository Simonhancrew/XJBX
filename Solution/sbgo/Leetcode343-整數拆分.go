package sbgo

//想最后一步拆分多少出来才能是解最优?
//我拆分一个j出来，确定了当前的i拆分是最大的，所以之前的一拆分出的i-j也应该是最大的
//于是就形成了递推

func integerBreak(n int) int {
	dp := make([]int, n+1)
	dp[2] = 1
	for i := 3; i <= n; i++ {
		cur := 0
		for j := 1; j < i; j++ {
			//加入cur的原因是如果此轮i中,之前的j拆分的更大
			//不要丢失在i循环内此时的的最大值
			cur = max(max(cur, j*(i-j)), dp[i-j]*j)
		}
		dp[i] = cur
	}
	return dp[n]
}
