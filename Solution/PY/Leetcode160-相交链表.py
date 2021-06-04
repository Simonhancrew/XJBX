# class Solution:
#     def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
#         mp = set()
#         cur = headA
#         while cur is not None:
#             mp.add(cur)
#             cur = cur.next
#         cur = headB
#         while cur is not None:
#             if cur in mp:
#                 return cur
#             cur = cur.next
#         return None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if headA is None or headB is None:
            return None
        cura,curb = headA,headB
        while cura != curb:
            cura = cura.next if cura is not None else headB
            curb = curb.next if curb is not None else headA
        return cura