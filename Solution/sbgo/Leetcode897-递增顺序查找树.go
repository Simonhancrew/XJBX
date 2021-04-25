package sbgo

func increasingBST(root *TreeNode) *TreeNode {
	dummyNode := &TreeNode{}
	resNode := dummyNode

	var dfs func(*TreeNode)
	dfs = func(node *TreeNode) {
		if node == nil {
			return
		}
		dfs(node.Left)

		resNode.Right = node
		node.Left = nil
		resNode = node

		dfs(node.Right)
	}
	dfs(root)

	return dummyNode.Right
}
