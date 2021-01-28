from typing import List
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        #前闭后开，只有一个元素就不必归并
        def sortfunc(head,tail)->ListNode:
            if not head:
                return head
            if head.next == tail:
                head.next = None
                return head
            slow = head
            fast = head
            while fast != tail:
                slow = slow.next
                fast = fast.next
                if fast != tail:
                    fast = fast.next
            mid = slow
            return merge(sortfunc(head,mid),sortfunc(mid,tail))
        def merge(head1,head2)->ListNode:
            dummy = ListNode(0)
            tmp,tmp1,tmp2 = dummy,head1,head2
            while tmp1 and tmp2:
                if tmp1.val <= tmp2.val:
                    tmp.next = tmp1
                    tmp1 = tmp1.next
                else:
                    tmp.next = tmp2
                    tmp2 = tmp2.next
                tmp = tmp.next
            if tmp1:
                tmp.next = tmp1
            elif tmp2:
                tmp.next = tmp2
            return dummy.next
        return sortfunc(head,None)
