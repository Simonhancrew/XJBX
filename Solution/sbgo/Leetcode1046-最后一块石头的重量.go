package sbgo

import (
	"container/heap"
	"sort"
)

//其实[]int也可以，只要提供heap的Push,Pop还有swap和Less就可以了,t他继承了sort的interface
type hp struct{ sort.IntSlice }

func (h *hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v interface{}) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() interface{} {
	n := len(h.IntSlice)
	tmp := h.IntSlice[n-1]
	h.IntSlice = h.IntSlice[:n-1]
	return tmp
}
func (h *hp) push(v int) { heap.Push(h, v) }
func (h *hp) pop() int   { return heap.Pop(h).(int) }

func lastStoneWeight(stones []int) int {
	q := &hp{stones}
	heap.Init(q)
	for q.Len() > 1 {
		x, y := q.pop(), q.pop()
		if x > y {
			q.push(x - y)
		}
	}
	if q.Len() > 0 {
		return q.IntSlice[0]
	}
	return 0
}
