#include "ADT.hpp"
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add =0;
        int sum =0;
        bool carry =false;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* headA = new ListNode(0);
        ListNode* head3 = headA;
        while(head1||head2){
           sum = 0;
           if (head1){
               sum+=head1->val;
               head1 = head1->next;
           }
           if(head2){
               sum+=head2->val;
               head2 = head2->next;
           }
           if (carry){
               sum+=1;
           }
           head3->next = new ListNode(sum%10);
           //不要忘记将head3也向前推进
           head3 = head3->next;
           carry = sum>=10?1:0;

        }
        if (carry){
            head3->next =new ListNode(1);
        }
        return headA->next;
    }
};