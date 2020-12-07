#include "ADT.hpp"
//双指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head,*slow = head;
        ListNode *meet=nullptr;
        //快慢指针相交一定有环
        while (fast){
            slow = slow->next;
            fast = fast->next;
            if(!fast){
                return nullptr;
            }
            fast = fast->next;
            if (fast == slow){
                meet = fast;
                break;//有环一定记得break
            }
        }
        if(meet == nullptr){
            return nullptr;
        }
        //从快慢指针相遇处，从head和这个点起，同stride走，相遇出就是环的入口
        while(meet&&head){
            if(meet == head){
                return meet;
            }
            meet = meet->next;
            head = head->next;
        }
        return nullptr;
    }
};