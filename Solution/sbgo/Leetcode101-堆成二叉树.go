package sbgo

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return isSymmetricrecursive(root.Left, root.Right)
}

func isSymmetricrecursive(left, right *TreeNode) bool {
	if left != nil && right != nil {
		return left.Val == right.Val && isSymmetricrecursive(left.Left, right.Right) && isSymmetricrecursive(left.Right, right.Left)
	}
	return left == nil && right == nil
}
