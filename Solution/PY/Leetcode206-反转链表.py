from typing import List

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        cur = head
        if head == None:
            return head
        while cur != None:
            tmp = cur.next
            cur.next = prev
            prev = cur 
            cur = tmp
        return prev 