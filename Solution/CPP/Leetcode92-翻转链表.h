#include "ADT.hpp"
//翻转链表一般要存下第二个节点的next节点，否则关系断开的话就无法继续往后跳
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right){
            return head;
        }
        //head节点是可能改变的，一般这种头节点可能被改变的需要开dummy节点
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto a = dummy;
        for(int i = 0;i < left - 1;i++) a = a->next;
        auto b = a->next,c = b->next;
        for(int i = 0;i < right - left;i++){
            auto d = c->next;
            c->next = b;
            b = c,c = d;
        }
        a->next->next = c;
        a->next = b;
        auto res = dummy->next;
        delete dummy;
        return res;
    }
};