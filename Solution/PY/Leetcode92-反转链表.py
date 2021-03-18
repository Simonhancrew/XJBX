class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        dummy = ListNode(-1)
        dummy.next = head
        a = dummy
        for i in range(left - 1):
            a = a.next
        b  = a.next
        c = b.next
        for i in range(right - left):
            d = c.next
            c.next = b
            b,c = c,d
        a.next.next = c
        a.next  = b
        return dummy.next
        