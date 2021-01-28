package sbgo

func sortList(head *ListNode) *ListNode {
	merge := func(head1, head2 *ListNode) *ListNode {
		dummy := &ListNode{}
		tmp, tmp1, tmp2 := dummy, head1, head2
		for tmp1 != nil && tmp2 != nil {
			if tmp1.Val <= tmp2.Val {
				tmp.Next = tmp1
				tmp1 = tmp1.Next
			} else {
				tmp.Next = tmp2
				tmp2 = tmp2.Next
			}
			tmp = tmp.Next
		}
		if tmp1 != nil {
			tmp.Next = tmp1
		} else if tmp2 != nil {
			tmp.Next = tmp2
		}
		return dummy.Next
	}
	var sortfunc func(head, tail *ListNode) *ListNode
	sortfunc = func(head, tail *ListNode) *ListNode {
		if head == nil {
			return head
		}
		if head.Next == tail {
			head.Next = nil
			return head
		}
		fast, slow := head, head
		for fast != tail {
			fast = fast.Next
			slow = slow.Next
			if fast != tail {
				fast = fast.Next
			}
		}
		mid := slow
		return merge(sortfunc(head, mid), sortfunc(mid, tail))
	}
	return sortfunc(head, nil)
}
