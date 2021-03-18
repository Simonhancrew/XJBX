package sbgo

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	dummy := &ListNode{Val: -1}
	dummy.Next = head
	a := dummy
	for i := 0; i < left-1; i++ {
		a = a.Next
	}
	b := a.Next
	c := b.Next
	for i := 0; i < right-left; i++ {
		d := c.Next
		c.Next = b
		b, c = c, d
	}
	a.Next.Next = c
	a.Next = b
	return dummy.Next
}
