package sbgo

var res int

func minCameraCover(root *TreeNode) int {
	if root == nil {
		return 0
	}
	res = 0
	if dfs(root) == 0 {
		res++
	}
	return res
}

func dfs(node *TreeNode) int {
	if node == nil {
		return 2
	}
	left := dfs(node.Left)
	right := dfs(node.Right)

	if left == 2 && right == 2 {
		return 0
	}
	//一定要先判断0的情况
	if left == 0 || right == 0 {
		res++
		return 1
	}
	if left == 1 || right == 1 {
		return 2
	}

	//走不到这里的
	return -1
}
