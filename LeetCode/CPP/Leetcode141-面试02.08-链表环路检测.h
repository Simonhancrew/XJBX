#include "ADT.hpp"
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow;
        ListNode* fast;
        slow = head;
        fast =head;
        while(fast){
            slow = slow->next;
            fast = fast->next;
            if(fast ==nullptr){
                return false;
            }
            fast = fast->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};