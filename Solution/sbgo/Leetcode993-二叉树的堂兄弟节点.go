package sbgo

func isCousins(root *TreeNode, x int, y int) bool {
	var xp, yp *TreeNode
	var xd, yd int
	var fdx, fdy bool
	check := func(node, parent *TreeNode, deep int) {
		if node.Val == x {
			xp = parent
			xd = deep
			fdx = true
		}
		if node.Val == y {
			yp, yd, fdy = parent, deep, true
		}
	}
	type pair struct {
		node *TreeNode
		deep int
	}
	que := []pair{{root, 0}}
	check(root, nil, 0)
	for len(que) > 0 {
		node, deep := que[0].node, que[0].deep
		que = que[1:]
		if node.Left != nil {
			que = append(que, pair{node.Left, deep + 1})
			check(node.Left, node, deep+1)
		}
		if node.Right != nil {
			que = append(que, pair{node.Right, deep + 1})
			check(node.Right, node, deep+1)
		}
		if fdx && fdy {
			break
		}
	}
	return xd == yd && xp != yp
}
