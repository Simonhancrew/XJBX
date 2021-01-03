package sbgo

//直接开两个链表去做

func partition(head *ListNode, x int) *ListNode {
	small := &ListNode{0, nil}
	big := &ListNode{0, nil}
	smallhead := small
	bighead := big
	for head != nil {
		if head.Val < x {
			smallhead.Next = head
			smallhead = smallhead.Next
		} else {
			bighead.Next = head
			bighead = bighead.Next
		}
		head = head.Next
	}
	bighead.Next = nil
	smallhead.Next = big.Next
	return small.Next
}
