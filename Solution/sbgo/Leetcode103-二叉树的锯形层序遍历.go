package sbgo

func zigzagLevelOrder(root *TreeNode) [][]int {
	var ans [][]int
	if root == nil {
		return ans
	}
	que := []*TreeNode{root}
	var direction = 0
	for len(que) > 0 {
		cur := []int{}
		q := que
		que = nil
		for _, node := range q {
			cur = append(cur, node.Val)
			if node.Left != nil {
				que = append(que, node.Left)
			}
			if node.Right != nil {
				que = append(que, node.Right)
			}
		}
		if direction%2 == 1 {
			reverse(cur)
		}
		direction++
		ans = append(ans, cur)
	}
	return ans
}

func reverse(cur []int) {
	var n = len(cur)
	i := 0
	j := n - 1
	for i <= j {
		cur[i], cur[j] = cur[j], cur[i]
		i++
		j--
	}
}
