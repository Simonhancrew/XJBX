#include "ADT.hpp"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto ptr = head;
        while(ptr){
            auto cur = ptr->next;
            while(cur && cur->val == ptr->val){
                cur = cur->next;
            }
            ptr->next = cur;
            ptr = ptr->next;
        }
        return head;
    }
};