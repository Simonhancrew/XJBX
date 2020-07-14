class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head,*slow = head;
        ListNode *meet=NULL;
        while (fast){
            slow = slow->next;
            fast = fast->next;
            if(!fast){
                return NULL;
            }
            fast = fast->next;
            if (fast == slow){
                meet = fast;
                break;//有环一定记得break
            }
        }
        if(meet == NULL){
            return NULL;
        }   
        while(meet&&head){
            if(meet == head){
                return meet;
            }
            meet = meet->next;
            head = head->next;
        }
        return NULL;
    }
};