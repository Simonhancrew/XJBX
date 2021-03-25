#include "ADT.hpp"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        ListNode* dummy = new ListNode(-101);
        dummy->next = head;
        auto pre = dummy,cur = head,after = head ->next;
        while(cur != nullptr){
            if(!after){
                return dummy->next;
            }
            if(cur->val == after->val){
                while(after && cur->val == after->val ){
                    after = after->next;
                }
                pre->next = after;
                cur = after;
                if(cur){
                    after = cur->next;
                }
            }else{
                pre = cur;
                cur = after;
                if(after){
                    after = after->next;
                }
            }
        }
        return dummy->next;
    }
};