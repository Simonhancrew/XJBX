#define a Listnode
class ListNode:
    def __init__(self,val,next = None):
        self.val = val
        self.next = None

#insertsort 
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        #dummy节点的加入是为了方便再头部加入元素
        dummy = ListNode(0)
        dummy.next = head
        lastordered = head
        cur = head.next
        while cur:
            if cur.val >= lastordered.val:
                lastordered = lastordered.next
            else:
                pre = dummy
                while pre.next.val <= cur.val:
                    pre = pre.next
                lastordered.next = cur.next
                cur.next = pre.next
                pre.next = cur
            cur = lastordered.next
        return dummy.next