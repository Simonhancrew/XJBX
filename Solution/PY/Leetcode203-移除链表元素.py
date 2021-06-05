class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy,tmp = ListNode(),head
        dummy.next = head
        pre = dummy
        while tmp:
            if tmp.val == val:
                pre.next = tmp.next
                tmp = tmp.next
            else:
                pre = pre.next
                tmp = tmp.next
        return dummy.next
