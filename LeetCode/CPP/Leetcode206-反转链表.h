#include "ADT.hpp"
//双指针的方法去就地反转
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr,*Lnext = nullptr;
        if(head == nullptr){
            return head;
        }
        while(head->next != nullptr){
            Lnext = head->next;
            head->next = pre;
            pre = head;
            head = Lnext;
        }
        head->next =pre;
        return head;
    }
};