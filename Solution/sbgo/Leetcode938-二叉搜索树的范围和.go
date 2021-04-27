package sbgo

func rangeSumBST(root *TreeNode, low int, high int) int {
	res := 0
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		if root.Val <= high && root.Val >= low {
			res += root.Val
		}
		dfs(root.Right)
	}
	dfs(root)
	return res
}
