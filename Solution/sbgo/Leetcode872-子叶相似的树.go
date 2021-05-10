package sbgo

//go在函数参数里放[]int的时候也是值传递
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	res1 := []int{}
	res2 := []int{}
	var getnode func(*TreeNode, *[]int)
	getnode = func(root *TreeNode, res *[]int) {
		if root == nil {
			return
		}
		if root.Left == nil && root.Right == nil {
			*res = append(*res, root.Val)
		}
		getnode(root.Left, res)
		getnode(root.Right, res)
	}
	getnode(root1, &res1)
	getnode(root2, &res2)
	if len(res1) != len(res2) {
		return false
	}
	for i := range res1 {
		if res1[i] != res2[i] {
			return false
		}
	}
	return true
}
