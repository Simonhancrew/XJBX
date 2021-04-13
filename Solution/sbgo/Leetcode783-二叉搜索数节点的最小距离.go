package sbgo

func minDiffInBST(root *TreeNode) int {
	var ans int = 2e9
	first := true
	pre := 0
	var dfs func(root *TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		if !first {
			ans = min(ans, root.Val-pre)
		}
		pre = root.Val
		first = false
		dfs(root.Right)
	}
	dfs(root)
	return ans
}
