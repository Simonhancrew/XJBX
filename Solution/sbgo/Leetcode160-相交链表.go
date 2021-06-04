package sbgo

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}
	cura, curb := headA, headB
	for cura != curb {
		if cura == nil {
			cura = headB
		} else {
			cura = cura.Next
		}
		if curb == nil {
			curb = headA
		} else {
			curb = curb.Next
		}
	}
	return cura
}
