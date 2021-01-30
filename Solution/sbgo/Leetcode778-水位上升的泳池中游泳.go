package sbgo

import "container/heap"

//定义一下优先队列，一个节点一个slice和5个方法

type Node struct {
	x, y, val int
}
type hp []Node

func (n hp) Len() int            { return len(n) }
func (n hp) Less(i, j int) bool  { return n[i].val < n[j].val }
func (n hp) Swap(i, j int)       { n[i], n[j] = n[j], n[i] }
func (n *hp) Push(x interface{}) { *n = append(*n, x.(Node)) }
func (n *hp) Pop() interface{} {
	old := *n
	size := len(old)
	x := old[size-1]
	*n = old[:size-1]
	return x
}

var dirs = [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}

func swimInWater(grid [][]int) int {
	n := len(grid)
	seen := make([][]bool, n)
	for i := range seen {
		seen[i] = make([]bool, n)
	}
	ans := 0
	seen[0][0] = true
	//此处要取地址，接口要求
	h := &hp{{0, 0, grid[0][0]}}
	for {
		e := heap.Pop(h).(Node)
		ans = max(ans, e.val)
		if e.x == n-1 && e.y == n-1 {
			break
		}
		for _, d := range dirs {
			if nx, ny := e.x+d[0], e.y+d[1]; 0 <= nx && nx < n && 0 <= ny && ny < n && !seen[nx][ny] {
				seen[nx][ny] = true
				heap.Push(h, Node{nx, ny, grid[nx][ny]})
			}
		}
	}
	return ans
}
