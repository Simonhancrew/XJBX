#include "ADT.hpp"
//链表的题目其实画图就出来了
//奇位置的链表相连，然后偶位置的链表相连
//最后将奇偶相连就完成
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        //奇头
        ListNode* odd = head;
        //偶头
        ListNode* evenHead = head -> next;
        //偶迭代
        ListNode* even = evenHead;
        //偶合法
        while(even != nullptr && even -> next != nullptr){
            odd -> next = even -> next;
            odd = odd -> next;
            even -> next = odd -> next;
            even = even -> next;
        }
        odd ->next = evenHead;
        return head;
    }
};