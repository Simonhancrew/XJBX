package sbgo

func reverseList(head *ListNode) *ListNode {
    var prev *ListNode
    cur := head
    if head == nil{
        return head
    }
    for cur != nil{
        tmp := cur.Next
        cur.Next = prev
        prev = cur
        cur = tmp
    }
    return prev
}