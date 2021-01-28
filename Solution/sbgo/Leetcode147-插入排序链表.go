package sbgo

func insertionSortList(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	dummy := &ListNode{}
	dummy.Next = head
	cur := head.Next
	lastOrdered := head
	for cur != nil {
		if cur.Val >= lastOrdered.Val {
			lastOrdered = lastOrdered.Next
		} else {
			pre := dummy
			for pre.Next.Val <= cur.Val {
				pre = pre.Next
			}
			lastOrdered.Next = cur.Next
			cur.Next = pre.Next
			pre.Next = cur
		}
		cur = lastOrdered.Next
	}
	return dummy.Next
}
